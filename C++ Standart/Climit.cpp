#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

int main(int argc, char ** argv) {
	int n_int = INT_MAX;
	short n_short = SHRT_MAX;
	long n_long = LONG_MAX;
	long long n_llong = LLONG_MAX;
	
	cout << "Int is " << sizeof(int) << " Bytes" << endl;
	cout << "Short is " << sizeof n_short << " Bytes" << endl;
	cout << "Long is " << sizeof n_long << " Bytes" << endl;
	cout << "Long Long is " << sizeof n_llong << " Bytes" << endl;
	
	cout << "Max Sizes are: " << endl;
	cout << "int: " << n_int << endl;
	cout << "short: " << n_short << endl;
	cout << "long: " << n_long << endl;
	cout << "long long: " << n_llong << endl;
	cout << "Unsigned long long: " << ULLONG_MAX << endl;
	cout << "Unsigned char: " << UCHAR_MAX << endl;
	
	cout << "Minimum int value: " << INT_MIN << endl;
	cout << "Bits per byte: " << CHAR_BIT << endl;
	
}


