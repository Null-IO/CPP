#include <iostream>
#include <cmath>
#include "Header.h"
using namespace std;

double Area(double l, double w) {
	if (l <= 0 || w <= 0)
		throw BadDims2D(l, w);
	else
		return l * w;
}

double Volume(double l, double w, double h) {
	if (l <= 0 || w <= 0 || h <= 0)
		throw BadDims3D(l, w, h);
	else
		return l * w * h;
}

int main() {
	double a, b, c;
	cout << "Please input 3 dimensions(l, w, h): ";
	
	while (cin >> a >> b >> c) {
		try {
			cout << "Area for a square: " << Area(a, b) << endl;
			cout << "Volume for a cube: " << Volume(a, b, c) << endl;
			cout << "input 3 dimensions(l, w, h): ";
		
		} catch (BadDims2D & bd) {
			bd.ErrorMsg();
			cout << "Try again" << endl;
			continue;
		}
		catch (...) {
			cout << "Unknown Error :(" << endl;
		}
	}

	return 0;
}
