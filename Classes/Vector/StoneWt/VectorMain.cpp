#include <cstdlib>
#include <iostream>
#include "Header.h"
#include <ctime>
using namespace std;

int main(int argc, char** argv) {
	int moreThanEleven = 0, input = 0;
	Stonewt Arr[6];
	Stonewt compareObj(11);
	srand(time(NULL));

	cout << "Initializing first 3 elements: " << endl;
	for (int i = 0; i < 3; i++) {
		Arr[i] = Stonewt(rand() % 20);
		
		if (Arr[i] < compareObj)
			moreThanEleven++;
	}

	cout << "Initializing other elements: " << endl;
	for (int i = 3; i < 6; i++) {
		cout << "Enter desired value: ";
		cin >> input;
		Arr[i] = Stonewt(input);

		if (Arr[i] < compareObj)
			moreThanEleven++;
	}

	cout << "Elements more than 11: " << moreThanEleven << endl;

	return 0;
}


