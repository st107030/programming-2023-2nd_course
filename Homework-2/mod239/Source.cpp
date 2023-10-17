#include <iostream>

class Mod239
{
public:
	int cl;

	Mod239(int cl = 0) : cl(cl % 239){}
	~Mod239(){}

	int mod(int cl) { return cl % 239; }
	int inversed(int cl)
	{
		if (cl == 0) { return -1; }
		if (cl == 1) { return 0; }
		int i = 2;
		while ((cl * i)%239 != 1) ++i;
		return i;
	}

	Mod239 operator+ (Mod239 num) { return Mod239(mod(num.cl + cl)); }
	Mod239 operator- (Mod239 num) { return Mod239(mod(cl - num.cl + 239)); }
	Mod239 operator* (Mod239 num) { return Mod239(mod(num.cl * cl)); }
	Mod239 operator/ (Mod239 num) 
	{ 
		if (num.cl != 0)
		{
			return Mod239(inversed(num.cl) * cl);
		}
		std::cout << " то тут у нас на 0 делит" << std::endl;
		return -1;
	}

	Mod239 operator+= (Mod239 num)
	{
		cl = mod(cl + num.cl);
		return *this;
	}
	Mod239 operator-= (Mod239 num)
	{
		cl = mod(cl = num.cl + 239);
		return *this;
	}
	Mod239 operator*= (Mod239 num)
	{
		cl = mod(cl * num.cl);
		return *this;
	}
	Mod239 operator/= (Mod239 num)
	{
		if (num.cl != 0) cl = mod(cl * inversed(num.cl));
		else cl = -1;
		return *this;
	}
	Mod239 operator%= (Mod239 num)
	{
		if (num.cl != 0) cl = mod(cl % num.cl);
		else cl = -1;
		return *this;
	}

	Mod239 operator=(const Mod239& c)
	{
		return Mod239(c.cl % 239);
	};
	bool operator == (const Mod239& c) const
	{
		return cl == c.cl;
	}
	bool operator != (const Mod239& c) const
	{
		return cl != c.cl;
	}
	bool operator > (const Mod239& c) const
	{
		return cl > c.cl;
	}
	bool operator < (const Mod239& c) const
	{
		return cl < c.cl;
	}
	bool operator >= (const Mod239& c) const
	{
		return cl >= c.cl;
	}
	bool operator <= (const Mod239& c) const
	{
		return cl <= c.cl;
	}

	unsigned long power(unsigned long a, unsigned long x, unsigned long p)
	{
		unsigned long result = 1;

		while (x)
		{
			if (x % 2 == 0)
			{
				x /= 2;
				a *= a % p;
			}
			else
			{
				x--;
				result *= a % p;
			}
		}
		return result % p;
	}

	friend std::ostream& operator<<(std::ostream& stream, const Mod239& c);
	friend std::istream& operator >> (std::istream& in, Mod239& num);
};

std::ostream& operator<<(std::ostream& stream, const Mod239& c)
{
	stream << c.cl << "(239)";
	return stream;
};

std::istream& operator >> (std::istream& in, Mod239& num)
{
	int cl;
	in >> cl;
	num.cl = cl % 239;
	return in;
}

int main(int argc, char* argv[])
{
	Mod239 a;
	Mod239 b = 14;
	std::cin >> a;
	std::cout << a << std::endl;
	std::cout << a - 500 << std::endl;
	std::cout << a + 100 << std::endl;
	std::cout << a * 56 << std::endl;
	std::cout << a / 12 << std::endl; //a * 20
	if (a != 8) { a *= b; std::cout << a << std::endl; }
	std::cout << a.power((unsigned long)(a.cl),238,239);
	return EXIT_SUCCESS;
}