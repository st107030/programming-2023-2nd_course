#pragma once
#include <string>

enum Subject
{
    None = 0,
    Algebra = 1,
    Calculus = 2,
    Mechanics = 3,
    Geometry = 4,
    Topology = 5,
    Programming = 6
};

class Test
{
public:
    Subject subject;
    std::string gr;//ABCDEF
 
    Test(Subject subject = None, std::string gr = "F") : subject(subject), gr(gr) {};
    ~Test() {};;
};
class Exam : public Test
{
public:
    int grade; //2345
    Exam(int grade = 2) : grade(grade) {};
    ~Exam() {};
};

class Student
{
public:
    std::string name;
    int course;
    double attendance;
    double average;
    Student(std::string name = " ", int course = 1, double attendance = 0, double average = 0) :
        name(name), course(course), attendance(attendance), average(average) {};
    ~Student() {}; 

    void print_st();
};
class Master : public Student
{
public:
    Subject major_subject;
    Master(Subject major_subject) : major_subject(major_subject) {};
    ~Master() {};

    void print_ms();
};

class Staff
{
public:
    std::string name;
};
class Professor : public Staff
{
public:
    Subject subject;
    double bonus = 0.5;
    Professor(std::string name, Subject subject) 
    {
        this->name = name;
        this->subject = subject;
    }
    ~Professor() {};
    void print_prof();
};

class Postgraduate : public Staff, public Master
{

};

std::string sub_en(Subject);

std::string get_gr(Test sub, Student st);
std::string get_gr(Test sub, Master st);
int get_grade(Test sub, Student st);
int get_grade(Test sub, Master st);

void test();

void test_exam();