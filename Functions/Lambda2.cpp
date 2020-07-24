#include <iostream>
#include <cstdio>
#include <functional>
using namespace std;

function<int(int, int, int)> returnLambda() {
	return [] (int x, int y, int z) {
		return x * y * z;
	};
}

int main(int argc, char ** argv) {
	auto l2 = returnLambda();
	cout << l2(6, 7, 8) << endl;
}


