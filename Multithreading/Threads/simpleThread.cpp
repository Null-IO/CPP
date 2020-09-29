#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>
using namespace std;

int randNum(int max) {
	srand(time(NULL));
	return rand() % max + 1;
}

void executeThread(int id) {
	auto nowTime = chrono::system_clock::now(); //in milliseconds
	time_t sleepTime = chrono::system_clock::to_time_t(nowTime);
	struct tm localTime;
	localtime_s(&localTime, &sleepTime); //converts to tm structure

	char tt[26] {};
	ctime_s(tt, sizeof(tt), &sleepTime); //Convert a time value to a string
	cout << "Thread " << id << " Sleep Time: " << tt;

	cout << "Month: " << localTime.tm_mon << endl;
	cout << "Day: " << localTime.tm_mday << endl;
	cout << "Year: " << localTime.tm_year + 1900 << endl;
	cout << "Hours: " << localTime.tm_hour << endl;
	cout << "Minutes: " << localTime.tm_min << endl;
	cout << "Seconds: " << localTime.tm_sec << endl;

	this_thread::sleep_for(chrono::seconds(randNum(3)));
	nowTime = chrono::system_clock::now();
	sleepTime = chrono::system_clock::to_time_t(nowTime);
	ctime_s(tt, sizeof(tt), &sleepTime);
	cout << "Thread " << id << " Awake Time: " << tt << endl;
}

int main(int argc, char** argv) {
	thread th1(executeThread, 1);
	th1.join(); //wait for th1 to end
	thread th2(executeThread, 2);
	th2.join();

	return 0;
}