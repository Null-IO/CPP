#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(int argc, char** argv) {
	cout << fixed << right;

	cout << setw(6) << "N" << setw(14) << "Square root" << setw(15) << "fourth root" << endl;

	double root = 0.0;

	for (size_t i = 10; i <= 100; i += 10) {
		root = sqrt(double(i));
		
		cout << setw(6) << setfill('.') << i << setfill(' ') << setw(12) << setprecision(3) << root
			<< setw(14) << setprecision(4) << sqrt(root)
			<< endl;
	}

	return 0;
}