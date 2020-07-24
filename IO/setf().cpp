#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char** argv) {
	// use left justification, show the plus sign, show trailing
	// zeros, with a precision of 3
	cout.setf(ios_base::left, ios_base::adjustfield);
	cout.setf(ios_base::showpos);
	cout.setf(ios_base::showpoint);
	cout.precision(3); //digits after . for ios_base::scientific & ios_base::fixed
	
	ios_base::fmtflags old = cout.setf(ios_base::scientific, ios_base::floatfield); //saving flags
	
	cout << "Left Justification:\n";
	for (int i = 1; i <= 41; i += 10) { //needs signed type to display +
		cout.width(4);
		cout << i << "|";
		cout.width(12);
		cout << sqrt(double(i)) << "|" << endl;
	}

	cout.setf(ios_base::internal, ios_base::adjustfield);
	cout.setf(old, ios_base::floatfield);

	cout << "Internal Justification:" << endl;
	for (int i = 1; i <= 41; i += 10) {
		cout.width(4);
		cout << i << "|";
		cout.width(12);
		cout << sqrt(double(i)) << "|" << endl;
	}

	cout.setf(ios_base::right, ios_base::adjustfield);
	cout.setf(ios_base::scientific, ios_base::floatfield);
	cout << "Right Justification:\n";
	for (int i = 1; i <= 41; i += 10) {
		cout.width(4);
		cout << i << "|";
		cout.width(12);
		cout << sqrt(double(i)) << "|\n";
	}

	cout.unsetf(ios_base::floatfield); //reset
	cout.unsetf(ios_base::showpos);
	cout << "Resetting formatting:" << endl;
	double d = 5.0 + (1.0 / 3.0);
	cout << d << endl;

	return 0;
}