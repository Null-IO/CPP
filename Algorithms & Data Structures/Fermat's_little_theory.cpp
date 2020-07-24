#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <algorithm>
using namespace std;

long long getRemainder(long long base, long long exp, long long m) {
	if (exp == 0)
		return 1;

	if (exp % 2 == 0)
		return ((long long)pow(getRemainder(base, exp / 2, m), 2) % m);
	else
		return (base * getRemainder(base, exp - 1, m) % m);
}

bool fastPrime(int n, int times, int randNum) {
	if (times == 0)
		return true;
	
	if (getRemainder(randNum, n, n) == randNum)
		fastPrime(n, times - 1, rand() % n);
	else
		return false;

}

int main(int argc, char** argv) {
	srand(time(NULL));
	long long a, b; cin >> a >> b;
	if (fastPrime(a, b, rand() % a))
		cout << "Prime" << endl;
	else
		cout << "Not Prime" << endl;
}


