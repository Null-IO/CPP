#include <iostream>
#include <cstdlib>
using namespace std;

double func(const double& d) { //"const" helps not to alter original data but pass it by reference!!!
	return d * d;
}

int main(int argc, char** argv) {
	double x = 6.9; int i = 5;
	double&& d = 2.3;
	cout << func(x) << endl;
	cout << func(x + 4.20) << endl; //Creates temporary variable
	cout << func(i) << endl; //Creates temporary variable as type is not matched

	cout << endl;

	double&& rref = sqrt(36.00);	
	double j = 15.0;
	double&& jref = 2.0 * j + 18.5;	//<-- rvalue reference
	cout << rref << '\n';
	cout << jref << '\n';				
}


