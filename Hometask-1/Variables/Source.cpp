#include <iostream>
/*
* As far as I am concerned, there is a correlation between size of a variable and place in memory.
* For example, sizeof(int) = 4 bytes, there is "int a" (consists of bytes a[0], a[1], a[2] and a[3])
* and some stack memory have already been used (so we've got nth memory cell free).
* If n % 4 == 0, then a[0] are written to the nth cell. Else it is written to the (n + 4 - (n % 4))th.
* 
* In the general case the cells are nth or (n + sizeof(type) - (n % syzeof(type)))th
*/


class A
{
public:
	char e[42]{}; // 42 bytes  
	// 0 -> 41
	bool h, g;// 1 * 2 bytes 
	// 42 -> 43
	int a; // 4 bytes 
	// 44 -> 47
	double c, d;  // 8 * 2 bytes
	// 48 -> 63
	int f[2]{ 0 };// 2 * 4 bytes
	// 64 -> 71
	int b; // 4 bytes
	// 72 -> 76
};

class Amax
{
public:
	bool h; // 1 byte
	// 0 -> 1
	double c; 
	// 8 - > 15
	bool g; // 1 byte
	// 16 -> 17
	double d;  // 8 bytes
	// 24 -> 31
	int a; // 4 bytes 
	// 32 -> 35
	char e[42]{}; // 42 bytes 
	// 36 -> 77
	int f[2]{ 0 }; // 2 * 4 bytes
	// 80 -> 87
	int b; // 4 bytes
	// 88 -> 92
};
//The number of memory cells should be a multiple of the most voluminous data type. (Idk why, it is just the experiment result)
//In these classes it is double (8 byte), so the sum will be 76 + 4 = 80 bytes in class A, and 92 + 4 = 96 bytes in class Amax 

int main(int argc, char* argv[])
{
	std::cout << sizeof(A) << std::endl;
	std::cout << sizeof(Amax);
	return 0;
}
