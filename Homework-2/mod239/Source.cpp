#include <iostream>

class Mod239
{
public:
	int cl;

	Mod239(int cl = 0) : cl(cl % 239){}
	~Mod239(){}

	int mod(int cl) 
	{ 
		while (cl < 0)
		{
			cl += 239;
		}
		return cl % 239; 
	}
	int inversed(int cl)
	{
		if (cl == 0) { return -1; }
		if (cl == 1) { return 0; }
		int i = 2;
		while ((cl * i)%239 != 1) ++i;
		return i;
	}

	Mod239 operator+= (Mod239 num)
	{
		cl = mod(cl + num.cl);
		return *this;
	}
	Mod239 operator-= (Mod239 num)
	{
		cl = mod(cl - num.cl);
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

	unsigned powmod(unsigned base, unsigned exp, unsigned modulo)
	{
		unsigned res = 1;

		while (exp != 0)
		{
			if ((exp & 1) != 0)
			{
				res = (1ll * res * base) % modulo;
			}

			base = (1ll * base * base) % modulo;
			exp >>= 1;
		}

		return res;
	}

	friend std::ostream& operator<<(std::ostream& stream, const Mod239& c);
	friend std::istream& operator >> (std::istream& in, Mod239& num);

	friend Mod239 operator+ (Mod239 num, Mod239 num2);
	friend Mod239 operator- (Mod239 num, Mod239 num2);
	friend Mod239 operator* (Mod239 num, Mod239 num2);
	friend Mod239 operator/ (Mod239 num, Mod239 num2);
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


Mod239 operator+ (Mod239 num, Mod239 num2) 
{ 
	Mod239 k = num.cl + num2.cl; 
	return k.mod(k.cl);
}
Mod239 operator- (Mod239 num, Mod239 num2) 
{ 
	Mod239 k = num.cl - num2.cl;
	return k.mod(k.cl);

}
Mod239 operator* (Mod239 num, Mod239 num2) 
{ 
	Mod239 k = num.cl * num2.cl;
	return k.mod(k.cl);
}
Mod239 operator/ (Mod239 num, Mod239 num2)
{
	if (num.cl != 0)
	{
		Mod239 k = num2.inversed(num2.cl) * num.cl;
		return k.mod(k.cl);
	}
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
	a += 1;
	std::cout << a << std::endl;
	a -= 9;
	std::cout << a << std::endl;
	a *= 100;
	std::cout << a << std::endl;
	a /= 10;
	std::cout << a << std::endl;
	std::cout << "a == 0 - " << (a == 0) << std::endl;
	std::cout << "a >= 0 - " << (a >= 0) << std::endl;
	std::cout << "a <= 0 - " << (a <= 0) << std::endl;
	std::cout << "a != 0 - " << (a != 0) << std::endl;
	std::cout << "a > 0 - " << (a > 0) << std::endl;
	std::cout << "a < 0 - " << (a < 0) << std::endl;
	std::cout << a.powmod((unsigned)(a.cl),238,239);
	return EXIT_SUCCESS;
}