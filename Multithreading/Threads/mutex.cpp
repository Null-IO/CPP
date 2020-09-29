#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>
#include <mutex>
using namespace std;

double acctBalance = 100;
mutex acctLock;

int randNum(int max) {
	srand(time(NULL));
	return rand() % max + 1;
}

string getTime(int id) {
	auto nowTime = chrono::system_clock::now(); //in milliseconds
	time_t sleepTime = chrono::system_clock::to_time_t(nowTime);
	char tt[26]{};
	ctime_s(tt, sizeof(tt), &sleepTime); //Convert a time value to a string

	return tt;
}

void getMoney(int id, double withdraw) {
	{
		lock_guard<mutex> lock(acctLock); //Prevents simultaneously thread access(only 1 thread can access this scope)
		this_thread::sleep_for(chrono::seconds(2));
		cout << id << " tries to withdraw $" << withdraw << " on " << getTime(id);
		if ((acctBalance - withdraw) >= 0) {
			acctBalance -= withdraw;
			cout << "New account balance is $" << acctBalance << endl;
		}
		else
			cout << "Not enough funds, current balance is $" << acctBalance << endl;

		cout << endl;
	}
}

int main(int argc, char** argv) {
	thread ths[10];
	for (size_t i = 0; i < 10; i++)
		ths[i] = thread(getMoney, i, 15);

	for (size_t i = 0; i < 10; i++)
		ths[i].join();

	return 0;
}