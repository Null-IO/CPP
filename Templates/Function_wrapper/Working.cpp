#include <iostream>
#include "Header.h"
using namespace std;

double dub(double x) { return 2.0 * x; }
double square(double x) { return x * x; }

int main(int argc, char** argv) {
	double y = 1.21;
	cout << "Function pointer dub:\n";
	cout << " " << use_f<double>(y, dub) << endl;
	cout << "Function pointer square:\n";
	cout << " " << use_f<double>(y, square) << endl;
	cout << "Function object Fp:\n";
	cout << " " << use_f<double>(y, Fp(5.0)) << endl;
	cout << "Function object Fq:\n";
	cout << " " << use_f<double>(y, Fq(5.0)) << endl;
	cout << "Lambda expression 1:\n";
	cout << " " << use_f<double>(y, [](double u) {return u * u; }) << endl;
	cout << "Lambda expression 2:\n";
	cout << " " << use_f<double>(y, [](double u) {return u + u / 2.0; }) << endl;

	return 0;
}