//[=] has access to all elemnets, but by copy value. [&] has access by reference.
//mutable lets lambda modify elements inside itself, but initial values are't changed!
//-> declares return type
#include <iostream>
#include <cstdio>
#include <time.h>
using namespace std;

int main(int argc, char ** argv) {
	int x = 69, y = 420;

auto l = [=] () mutable -> int {
	cout << x << " " << y << endl;
	++x;
	++y;
};
	srand(time(NULL));
	for(int i = 0; i < rand() % 10; i++)
		l();
	
	cout << "x: " << x << " y: " << y;
}


