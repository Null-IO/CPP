#include <iostream>
#include <cstdio>
using namespace std;

//not-standart for() and technique not to overflow long double
long double probability(unsigned number, unsigned choices) {
	long double chance = 1.0;
	for(long double n = number, c = choices; c > 0; n--, c--)
		chance *= n / c;
	
	return chance;
}
//arr[] is pointer to first element of Array
int sumArr(int arr[], int n) {
	int sum = 0;
	for(int i = 0; i < n; i++)
		sum += arr[i];
	
	return sum;
}

int main(int argc, char ** argv) {
	int Arr[5] = {3, 5, 7, 11, 13};
	cout << probability(47, 6) << endl;
	cout << sumArr(Arr + 2, 3);
}


