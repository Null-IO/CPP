#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>
#include <mutex>
#include <vector>
using namespace std;

mutex locker;

void findPrimes(unsigned int start, unsigned int end, vector<int>& vect) {
	for (size_t i = start; i <= end; i += 2) {
		for (size_t j = 2; j < i; j++) {
			if (i % j == 0)
				break;
			else if ((j + 1) == i) {
				lock_guard<mutex> lock(locker);
				vect.push_back(i);
			}
		}
	}
}

void getPrimeThread(unsigned int start, unsigned int end, unsigned int threadNum, vector<int>& primeVect) {
	vector<thread> threadVec;
	int threadSpreads = end / threadNum;
	int newEnd = start + threadSpreads - 1;

	for (size_t i = 0; i < threadNum; i++) {
		threadVec.emplace_back(findPrimes, start, newEnd, ref(primeVect)); //ref() when using reference in function prototype
		start += threadSpreads;
		newEnd += threadSpreads;
	}
	for (auto& i : threadVec)
		i.join();
}

int main(int argc, char** argv) {
	vector<int> primeVect;
	int startTime = clock();
	getPrimeThread(1, 100000, 12, primeVect); //12 is optimial number of threads
	int endTime = clock();

	cout << "Prime numbers:" << endl;
	for (auto& i : primeVect)
		cout << i << endl;
	
	cout << "Execution Time: " << (endTime - startTime) / double(CLOCKS_PER_SEC) << endl;

	return 0;
}