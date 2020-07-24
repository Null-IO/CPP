#include <iostream>
#include <cstdio>
#include <utility>
#include <string>
using namespace std;

int main(int argc, char ** argv) {
	pair<int, int> p = {5, 47};
	pair<int, string> p2 = {71, "This is a pair of string"};
	cout << "First is " << p.first << endl;
	cout << "Second is " << p.second << endl;
	
	cout << "First is " << p2.first << endl;
	cout << "Second is " << p2.second << endl;
}


