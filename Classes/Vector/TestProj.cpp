#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Header.h"

int main(int argc, char** argv) {
	using namespace std;
	using VECTOR::Vector;

	srand(time(NULL));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target, dstep;

	cout << "Enter target distance (q to quit): ";
	while (cin >> target)
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;

		while (result.magval() < target) {
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
		}
		cout << "After " << steps << " steps, the subject "
			"has the following location:\n";
		cout << result << endl;
		result.polar_mode();

		cout << " or\n" << result << endl;
		cout << "Average outward distance per step = "
			<< result.magval() / steps << endl;

		double d = result;
		cout << "Magnitude: " << d << endl;

		steps = 0;
		result.reset(0.0, 0.0);

		cout << endl << "Enter target distance(q to quit) :" << endl;
	}
	cout << "Bye" << endl;
	cin.clear();
	while (cin.get() != '\n')
		continue;

	return 0;
}
