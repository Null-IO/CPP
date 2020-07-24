#include <iostream>
#include <cmath>
#include "Header.h"

double hmean(double a, double b) {
	if (a == -b)
		throw bad_hmean(a, b);
	
	return 2.0 * a * b / (a + b);
}

double gmean(double a, double b) {
	if (a < 0 || b < 0)
		throw bad_gmean(a, b);
	
	return std::sqrt(a * b);
}

int main() {
	double x, y, z;
	x = y = z = 0.0;

	std::cout << "Enter two numbers: ";
	while (std::cin >> x >> y) {
		try {
			z = hmean(x, y);
			std::cout << "Harmonic mean of " << x << " and " << y
				<< " is " << z << std::endl;

			std::cout << "Geometric mean of " << x << " and " << y
				<< " is " << gmean(x, y) << std::endl;
			
			std::cout << "Enter next set of numbers <q to quit>: ";
		}
		catch (bad_hmean& bh) {
			bh.ErrMsg();
			std::cout << "Try again.\n";
			continue;
		}
		catch (bad_gmean & bg) {
			std::cout << bg.mesg();
			std::cout << "Values used: " << bg.v1 << ", "
				<< bg.v2 << std::endl;
			std::cout << "Sorry, you don't get to play any more.\n";
			break;
		}
	}
	std::cout << "Bye!\n";
	
	return 0;
}
