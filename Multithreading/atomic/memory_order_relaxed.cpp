#include <iostream>
#include <atomic>
#include <thread>
#include <vector>
using namespace std;

atomic<int> counter {0};
//wait-free and lock-free add(). C++ is love, C++ is life.
void add() {
	for (size_t i = 0; i < 1000; i++) {
		counter.fetch_add(1, memory_order::memory_order_relaxed); //Doesn't matter which threads modifies counter, we only care end result
	}
}

int main(int argc, char** argv) {
	vector<thread> ths;
	for (int n = 0; n < 10; ++n)
		ths.emplace_back(add); //spawning 10 threads
	
	for (auto& t : ths)
		t.join();

	cout << "Final counter value is " << counter << endl; //Always yields 10000.

	return 0;
}