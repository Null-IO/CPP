#include <iostream>
#include "Header.h"
using std::cout;
using std::cin;
using std::endl;

Worker::~Worker() {};

void Worker::Data() const {
	cout << "Name: " << fullname << endl;
	cout << "Employee ID: " << id << endl;
}

void Worker::Get() {
	getline(cin, fullname);
	cout << "Enter Worker's ID: ";
	cin >> id;

	while (cin.get() != '\n')
		continue;
}

void Waiter::Data() const {
	cout << "Panache rating: " << panache << endl;
}

void Waiter::Get() {
	cout << "Enter waiter's panache rating: ";
	cin >> panache;

	while (cin.get() != '\n')
		continue;
}

void Waiter::Set() {
	cout << "Enter waiter's name: ";
	Worker::Get();
	Get();
}

void Waiter::Show() const {
	cout << "Category: waiter\n";
	Worker::Data();
	Data();
}

char* Singer::pv[] = { (char*)"other", (char*)"alto", (char*)"contralto", (char*)"soprano", (char*)"bass", (char*)"baritone", (char*)"tenor" };

void Singer::Data() const {
	cout << "Vocal range: " << pv[voice] << endl;
}

void Singer::Get() {
	cout << "Enter number for singer's vocal range:\n";
	int i;
	for (i = 0; i < Vtypes; i++)
	{
		cout << i << ": " << pv[i] << " ";
		if (i % 4 == 3)
			cout << endl;
	}
	if (i % 4 != 0)
		cout << '\n';
	
	cin >> voice;

	while (cin.get() != '\n')
		continue;
}

void Singer::Set() {
	cout << "Enter singer's name: ";
	Worker::Get();
	Get();
}

void Singer::Show() const {
	cout << "Category: singer" << endl;
	Worker::Data();
	Data();
}

void SingerWaiter::Data() const {
	Waiter::Data();
	Singer::Data();
}

void SingerWaiter::Get() {
	Waiter::Get();
	Singer::Get();
}

void SingerWaiter::Set() {
	cout << "Enter singing waiter's name: ";
	Worker::Get();
	Get();
}

void SingerWaiter::Show() const {
	cout << "Category: singing waiter" << endl;
	Worker::Data();
	Data();
}