#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char ** argv) {
	float f, ft;
	double d;
	long double ld;
	
	printf("float is %ld bits\n", sizeof(f) * 8);
	printf("double is %ld bits\n", sizeof(d) * 8);
	printf("long double is %ld bits\n", sizeof(ld) * 8);
	
	ft = .1 + .1 + .1;
	if(ft == 0.3)
		printf("true");
	else					//<-- rounding error ft is more than 0.3!
		printf("false");
}


