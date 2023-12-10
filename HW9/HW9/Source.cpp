#include <iostream>
#include <thread>
#include <ctime>
#include <mutex>
#include <condition_variable>
#include "SF.h"

int main(int argc, char* argv[])
{
	srand(time(0));
	int k = rand() % 50; //tasks
	std::cout << k << std::endl;
	int n = rand() % 10; //threads
	int q = 0;
	int time_gen = rand() % 3000 + 1000; //time to generate
	int time_proc = rand() % 3000 + 1000; //time to do
	
	std::thread th1(data_generator, std::ref(q), std::ref(k), time_gen);
	std::thread th2(data_processor, std::ref(q), std::ref(k), time_proc);
	th1.join();
	th2.join();

	return 0;
}
