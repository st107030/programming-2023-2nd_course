#include <iostream>

class B
{
private:
	int f1() { std::cout << '1'; return 1; }
	void f2() { std::cout << "f2" << std::endl; }
	char f3() 
	{ return 'a'; }

	int(* ptr1)() { f1 };
	int n = f1();
	char k = f3();
public:
	B(int n = 0, char k = 'A') :n(n), k(k) {}
};

class B2
{
public:
	int f1() { return 0; }
	void f2() { std::cout << "f22" << std::endl; }
	char f3() { return 'b'; }

	int n2;
	char k2;
};

char& get_b(B& b)
{
	void* p = &b;
	B2* b2 = static_cast<B2*>(p);
	return b2->k2;
}

void ff1(B& b)
{
	void* p = &b;
	B2* b2 = static_cast<B2*>(p);
	b2->f1();
	int i = b2->f1();
	std::cout << i;
}
/*void nn(B& b, int num)
{
	reinterpret_cast<B2*>(&b)->n2 = num;
}
void ff1(B& b) {
	reinterpret_cast<B2*>(&b)->f1();
}
void ff2(B& b) {
	reinterpret_cast<B2*>(&b)->f2();
}
void ff3(B& b) {
	reinterpret_cast<B2*>(&b)->f3();
}*/
int main(int argc, char* argv[])
{
	B b;
	char ch = get_b(b);
	std::cout << ch;
	ff1(b);
	return EXIT_SUCCESS;
}
