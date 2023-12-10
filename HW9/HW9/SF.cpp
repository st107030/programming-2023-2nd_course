#include "SF.h"
#include <iostream>
#include <windows.h>
#include <condition_variable>
#include <mutex>

std::mutex mut;
std::condition_variable cv;

bool more_data_to_gen(int& k)
{
	if (k != 0)
	{
		k--;
		return true;
	}
	return false;
}

bool is_empty(int q)
{
	if (q == 0) return true;
	return false;
}

void data_generator(int& q, int& k, int t)
{
	while (more_data_to_gen(k))
	{
		std::unique_lock<std::mutex> lk (mut);
		q++;
		std::cout << "The process of generating is running." << std::endl;
		Sleep(t);
		cv.notify_one();
	}
}

void data_processor(int& q, int& k, int t)
{
	while (true)
	{
		std::unique_lock<std::mutex> lk(mut);
		cv.wait(lk, [=]() {return !is_empty(q); });
		q--;
		std::cout << "Task is running" << std::endl;
		lk.unlock();
		Sleep(t);

		if ((q == 0)&&(k == 0)) break;
	}
}