#include <iostream>
#include <mutex>
#include <thread>
#include "Queue.h"

int main()
{
	queue<int> q(1);
	
	std::thread th1(test1, std::ref(q));
	std::thread th2(test2, std::ref(q));
	std::thread th3(test3, std::ref(q));

	th1.join();
	th2.join();
	th3.join();
	return EXIT_SUCCESS;
}