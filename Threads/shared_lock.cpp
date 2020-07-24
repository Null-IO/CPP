//implements reader-writeer lock with shared_mutex
#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <map>
using namespace std;

map<string, int> teleBook{ {"Dijkstra", 1972}, {"Scott", 1976}, {"Ritchie", 1983} };

shared_timed_mutex teleBookMutex;

void addToTeleBook(const string& s, int tele) {
	lock_guard<shared_timed_mutex> writerLock(teleBookMutex); //gives exclusive writing to thread
	cout << endl << "STARTING UPDATE " << s;
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	teleBook[s] = tele;
	cout << " ... ENDING UPDATE " << s << endl;
}

void printNumber(const string& s) {
	shared_lock<shared_timed_mutex> readerLock(teleBookMutex); //gives shared reading capabilities to threads
	auto it = teleBook.find(s);
	if(it != teleBook.end())
		cout << s << ": " << teleBook[s] << endl;
	else
		cout << s << " not found" << endl;
}

int main(int argc, char** argv) {
	cout << endl;

	thread reader1([] {printNumber("Scott"); });
	thread reader2([] {printNumber("Ritchie"); });
	
	thread w1([] {addToTeleBook("Scott", 1968); });
	
	thread reader3([] {printNumber("Dijstra"); });
	thread reader4([] {printNumber("Scott"); });

	thread w2([] {addToTeleBook("Bjarne", 1965); });

	thread reader5([] {printNumber("Scott"); });
	thread reader6([] {printNumber("Ritchie"); });
	thread reader7([] {printNumber("Scott"); });
	thread reader8([] {printNumber("Bjarne"); });


	reader1.join();
	reader2.join();
	reader3.join();
	reader4.join();
	reader5.join();
	reader6.join();
	reader7.join();
	reader8.join();
	w1.join();
	w2.join();

	cout << endl;

	std::cout << "\nThe new telephone book" << std::endl;
	for (auto& it : teleBook)
		cout << it.first << " " << it.second << endl;
	
	cout << endl;

	return 0;
}