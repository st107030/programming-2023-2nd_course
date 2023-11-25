#include <iostream>
#include <ctime>
#include <windows.h>

void Fiber(int amount, int** arr)
{
	srand(time(0));

	int len = 0;
	for (int i = 0; i < amount; ++i)
	{
		len = len + 10 - arr[i][1];
	}

	int counter = 1;
	while (len != 0)
	{
		int* fb = new int[len];
		int num = 0;
		int pr = 10 - arr[num][1];
		for (int i = 0; i < len; ++i)
		{
			while (pr == 0)
			{
				num++;
				pr = 10 - arr[num][1];
			}
			fb[i] = num;
			pr--;
		}
		//the fyber array
		bool flag = true;

		while (flag)
		{
			int n = rand() % len;
			std::cout << counter << ") The process " << fb[n] + 1 << " is running." << std::endl;
			Sleep(1000);

			counter++;
			arr[fb[n]][0]--;
			if (arr[fb[n]][0] == 0)
			{
				std::cout << "PROCESS " << fb[n] + 1 << " IS FINISHED." << std::endl;
				len = len - 10 + arr[fb[n]][1];
				arr[fb[n]][1] = 10;
				flag = false;
			}
		}
		delete[] fb;
	}
}

void test()
{
	int amount = 4;
	int** arr = new int* [4];
	for (int i = 0; i < 4; ++i)
	{
		arr[i] = new int[2];
	}
	arr[0][0] = 10; //time
	arr[1][0] = 20;
	arr[2][0] = 5;
	arr[3][0] = 15;

	arr[0][1] = 1; //priority
	arr[1][1] = 4;
	arr[2][1] = 7;
	arr[3][1] = 3;

	Fiber(amount, arr);

	for (int i = 0; i < 4; ++i)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

int main()
{
	test();
	return EXIT_SUCCESS;
}