#include <iostream>
#include <cstdio>
using namespace std;

int Args(initializer_list<int> vals) {
	static int sum = 0;
	
	for(auto i : vals)
		sum += i;
	
	return sum;
}

int main(int argc, char ** argv) {
	int n, input; cin >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> input;
		Args({input});
	}
	cout << Args({0});
}


