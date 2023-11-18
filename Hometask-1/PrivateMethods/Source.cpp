#include <iostream>

class BP
{
public:
	virtual int f1() { return 2; }
	virtual void f2() { std::cout << "parent function" << std::endl; }
	virtual char f3() { return 'p'; }
};
class B: public BP
{
private:
	int f1() { std::cout << '1' << std::endl; return 1; }
	void f2() { std::cout << "f2" << std::endl; }
	char f3() { std::cout << "aaa" << std::endl; return 'a'; }
};

int main(int argc, char* argv[])
{
	B b;
	BP* b2 = &b;
	b2->f1();
	b2->f2();
	b2->f3();
	return EXIT_SUCCESS;
}
