#include <iostream>
#include <thread>
#include <future>
#include <deque>
#include <utility>
using namespace std;

class SumUp {
public:
	int operator()(int beg, int end) {
		long long sum {0};
		for (size_t i = beg; i < end; i++)
			sum += i;

		return sum;
	}
};

int main(int argc, char** argv) {
	SumUp sumUp1;
	SumUp sumUp2;
	SumUp sumUp3;
	SumUp sumUp4;

	//wrap the tasks
	packaged_task<int(int, int)> sumTask1(sumUp1); //callables that returns int with 2 int arguments
	packaged_task<int(int, int)> sumTask2(sumUp2);
	packaged_task<int(int, int)> sumTask3(sumUp3);
	packaged_task<int(int, int)> sumTask4(sumUp4);

	//create futures
	future<int> sumResult1 = sumTask1.get_future();
	future<int> sumResult2 = sumTask2.get_future();
	future<int> sumResult3 = sumTask3.get_future();
	future<int> sumResult4 = sumTask4.get_future();

	//push tasks to container
	deque<packaged_task<int(int, int)>> allTasks;
	allTasks.push_back(move(sumTask1));
	allTasks.push_back(move(sumTask2));
	allTasks.push_back(move(sumTask3));
	allTasks.push_back(move(sumTask4));

	int begin = 1;
	int increment = 2500;
	int end = begin + increment;

	//perform each calculation in a separate thread
	while (!allTasks.empty()) {
		packaged_task<int(int, int)> myTask = move(allTasks.front());
		allTasks.pop_front();
		thread sumThread(move(myTask), begin, end);
		begin = end;
		end += increment;
		sumThread.detach();
	}

	auto sum = sumResult1.get() + sumResult2.get() + sumResult3.get() + sumResult4.get();

	cout << "sum of 0 .. 10000 = " << sum << std::endl;

	return 0;
}