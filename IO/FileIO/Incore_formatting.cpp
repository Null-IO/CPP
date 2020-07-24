#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, char** argv) {
	ostringstream outstr;

	string hrdisk;
	cout << "What's the name of your hard disk? ";
	getline(cin, hrdisk);
	int cap;
	cout << "What's its capacity in GB? ";
	cin >> cap;
	outstr << "The hard disk " << hrdisk << " has a capacity of " << cap << " gigabytes.\n";
	string result = outstr.str();
	cout << result;
	
	string lit = "It was a dark and stormy day, and " " the full moon glowed brilliantly. ";
	istringstream instr(lit);
	string word;
	while(instr >> word)
		cout << word << endl;

	return 0;
}