#include <iostream>

class B
{
private:
	int f1() { return 1; }
	void f2() { std::cout << "f2" << std::endl; }
	char f3() { return 'a'; }
	friend int main(int argc, char* argv[]); //it was the dumbest idea, but it worked...
};
int main(int argc, char* argv[])
{
	B b;
	int a = b.f1();
	std::cout << a << std::endl;
	b.f2();
	char k = b.f3();
	std::cout << k;

	return EXIT_SUCCESS;
}