#include <iostream>
#include <cstdlib>
using namespace std;

const int Len = 66, Divs = 6;

void SubDivide(char ar[], int low, int high, int level) {
	if (level == 0)
		return;

	int mid = (high + low) / 2;
	ar[mid] = '|';
	
	SubDivide(ar, low, mid, level - 1);
	SubDivide(ar, mid, high, level - 1);
}

int main(int argc, char** argv) {
	char ruler[Len];
	for (int i = 1; i < Len - 2; i++)
		ruler[i] = ' ';
	ruler[Len - 1] = '\0';
	
	int max = 64, min = 0;
	ruler[min] = ruler[max] = '|';
	cout << ruler << endl;

	for (int i = 1; i <= Divs; i++) {
		SubDivide(ruler, min, max, i);
		cout << ruler << endl;

	}

	return 0;
}