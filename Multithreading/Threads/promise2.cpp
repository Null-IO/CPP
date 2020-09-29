#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std;

using namespace literals::chrono_literals;

void getAnswer(promise<int> intPromise) {
	this_thread::sleep_for(3s);
	intPromise.set_value(42);
}

int main(int argc, char** argv) {
	promise<int> answerPromise;
	auto fut = answerPromise.get_future();
	thread prodThread(getAnswer, move(answerPromise));
	future_status status{};
	
	do {
		status = fut.wait_for(0.2s); //returns future_ready enum
		std::cout << "... waiting on promise" << std::endl;
	
	} while (status != future_status::ready);

	cout << endl << "The Answer: " << fut.get() << endl;
	prodThread.join();

	return 0;
}