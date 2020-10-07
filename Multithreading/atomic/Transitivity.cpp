#include <iostream>
#include <atomic>
#include <thread>
#include <vector>
using namespace std;

vector<int> sharedWork;
atomic<bool> dataProduced(false);
atomic<bool> dataConsumed(false);

void dataProducer() {
	sharedWork = { 1, 0, 3 };
	dataProduced.store(true, memory_order_release);
}

void deliveryBoy() {
	while (!dataProduced.load(memory_order_acquire));
	dataConsumed.store(true, memory_order_release); //Transitivity between independant threads
}

void dataConsumer() {
	while (!dataConsumed.load(memory_order_acquire)); //While is needed, because if .load happens before .store, .load syncs with .store, but doesn't wait for .store and we get data race
	sharedWork[1] = 2;
}

int main(int argc, char** argv) {
	std::thread t1(dataConsumer);
	std::thread t2(deliveryBoy);
	std::thread t3(dataProducer);
	t1.join(); t2.join(); t3.join();

	for (auto& v : sharedWork)
		cout << v << " ";
	cout << endl;

	return 0;
}