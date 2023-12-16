#include "Class.h"
#include <iostream>
#include <cmath>
#include <ctime>
#include <random>

std::string sub_en(Subject sub)
{
    switch (sub)
    {
    case 1:
        return "Algebra";
    case 2:
        return "Calculus";
    case 3:
        return "Mechanics";
    case 4:
        return "Geometry";
    case 5:
        return "Topology";
    case 6:
        return "Programming";
    }
}

void Professor::print_prof() 
{
    std::cout << "Professor: " << name << std::endl;
    std::cout << "Subject: " << sub_en(subject) << std::endl;
}

void Student::print_st()
{
    std::cout << "Student: " << name << std::endl;
    std::cout << "Course: " << course << std::endl;
    std::cout << "Attendance: " << attendance << std::endl;
    std::cout << "Average grade: " << average << std::endl;
}

void Master::print_ms()
{
    print_st();
    std::cout << "Specialization: " << sub_en(major_subject) << std::endl;
}

std::string get_gr(Test sub, Student st)
{
    srand(time(0));
   //attendance 3/10, knowledge 5/10 luck 2/10
    int score = round((st.attendance * 3 + (st.average / 5) * 500 + rand() % 201) / 160);
    switch (score)
    {
    case 1:
        return "F";
    case 2:
        return "E";
    case 3:
        return "D";
    case 4:
        return "C";
    case 5:
        return "B";
    case 6:
        return "A";
    }
}

std::string get_gr(Test sub, Master st)
{
    srand(time(0));
    int i = 0;
    //attendance 2/10, knowledge 6/10 luck 1/10, maj 1/10
    if (sub.subject == st.major_subject) { i = 1; }
    int score = round((st.attendance * 2 + (st.average / 5) * 600 + rand() % 101 + i * (rand() % 101)) / 160);
    switch (score)
    {
    case 1:
        return "F";
    case 2:
        return "E";
    case 3:
        return "D";
    case 4:
        return "C";
    case 5:
        return "B";
    case 6:
        return "A";
    }
}

int get_grade(Exam sub, Student st)
{
    int i = 0;
    std::string s = get_gr(sub, st);
    if (s == "A") return 5;
    if ((s == "B") || (s == "C")) return 4;
    if ((s == "D") || (s == "E")) return 3;
    return 2;
}

int get_grade(Exam sub, Master st)
{
    std::string s = get_gr(sub, st);
    if (s == "A") return 5;
    if ((s == "B") || (s == "C")) return 4;
    if ((s == "D") || (s == "E")) return 3;
    return 2;
}


void test()
{
    Student st("Egor Toskuev", 2, 75, 4.4);
    Professor pr("Igor Lvovich", Mechanics);
    Test mech(Mechanics);
    mech.gr = get_gr(mech, st);
    pr.print_prof();
    st.print_st();
    if (mech.gr == "F")
    {
        std::cout << "Test has been failed.";
    }
    else std::cout << "Test has been passed with grade " << mech.gr << std::endl;
    std::cout << std::endl;
}

void test_exam()
{
    Master st(Algebra);
    st.name = "Petrov Petr";
    st.course = 6;
    st.attendance = 60;
    st.average = 3.7;
    Professor pr("Igor Lvovich", Algebra);
    Exam alg;
    alg.subject = Algebra;
    pr.print_prof();
    st.print_st();
    alg.grade = get_grade(alg, st);
    if (alg.grade == 2)
    {
        std::cout << "Exam has been failed.";
    }
    else std::cout << "Exam has been passed with grade " << alg.grade << std::endl;
}