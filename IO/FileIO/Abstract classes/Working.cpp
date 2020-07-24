#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <filesystem>
#include "Header.h"
using namespace std;

void mainFunc(fstream* fs, const char* fileName, bool firstTime = false) {
	vector<abstr_emp*> pc;

	if (!firstTime) {
		int classtype; char ch;
		while ((*fs >> classtype).get(ch)) {
			switch (classtype) {
				case classkind::Employee:
					pc.push_back(new employee);
					pc.back()->getAll(*fs);
					break;
				case classkind::Manager:
					pc.push_back(new manager);
					pc.back()->getAll(*fs);
					break;
				case classkind::Fink:
					pc.push_back(new fink);
					pc.back()->getAll(*fs);
					break;
				case classkind::Highfink:
					pc.push_back(new highfink);
					pc.back()->getAll(*fs);
					break;
			}
		}
		fs->clear();
		cout << "Here's the contents of a \"" << fileName << "\"" << endl << endl;
		for (auto& i : pc)
			i->ShowAll();

		pc.erase(pc.begin(), pc.end());
		cout << setw(32) << setfill('-') << "" << endl;
	}
	bool execute = true;
	while(execute) {
		cout << "Input object you are willing to store:" << endl;
		cout << "1: Employee\t 2: manager\t 3: fink\t 4: highfink" << endl;
		char obj = 'q'; cin >> obj;
		switch (obj) {
		case '1':
			pc.push_back(new employee());
			pc.back()->SetAll();
			break;
		case '2':
			pc.push_back(new manager());
			pc.back()->SetAll();
			break;
		case '3':
			pc.push_back(new fink());
			pc.back()->SetAll();
			break;
		case '4':
			pc.push_back(new highfink());
			pc.back()->SetAll();
			break;
		default:
			execute = false;
			break;
		}
	}
	if (pc.size() > 0) {
		cout << "Writing objects to file:" << endl;
		for (auto& i : pc)
			i->writeAll(*fs);
		cout << "Objects written to file successfully." << endl;
	}
	else
		cout << "No object were written." << endl;
}

int main(int argc, char** argv) {
	const char* fileName = "Employer.txt";
	fstream fs(fileName, ios_base::in | ios_base::app);

	uintmax_t size = filesystem::file_size(fileName);
	
	if (size == 0) {
		cout << "\"" << fileName << "\" is either empty or not created yet" << endl;
		mainFunc(&fs, fileName, true);
	}
	else
		mainFunc(&fs, fileName);

	fs.close();

	return 0;
}