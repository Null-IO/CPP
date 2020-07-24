#include <iostream>
#include <cmath>
#include <new>
using namespace std;

struct Big {
	double stuff[20000];
};

int main() {
	Big* pb;
	try {
		cout << "Trying to get a big block of memory:" << endl;
		pb = new Big[99999]; //1,600,000,000 bytes
		cout << "Got past the new request:" << endl;
	
	}
	catch (bad_alloc & ba) {
		cout << "Caught the exception!" << endl;
		cout << ba.what() << endl;
		exit(EXIT_FAILURE);
	}
	cout << "Memory Successfully allocated" << endl;
	pb[0].stuff[0] = 4;
	cout << pb[0].stuff[0] << endl;
	delete[] pb;
	
	return 0;
}
