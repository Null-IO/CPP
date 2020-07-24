#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(int argc, char ** argv) {
	vector<int> vi = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<int>::iterator it;
	
	cout << "Input iterator: " << endl;
	for(it = vi.begin(); it < vi.end(); ++it)
		cout << *it << " ";
	
	cout << endl;
	
	vector<int>::iterator start = vi.begin();
	vector<int>::iterator end = vi.end();
	
	cout << "output iterator:" << endl;
	for(it = start; it < end; it++) {
		cout << ++(*it) << " ";
		--(*it);
	}
	cout << endl;
	
	cout << "Forward iterator:" << endl; //if u are confused forward iterator just points to objects without modifying them
	for(it = start; it < end; ++it)
		cout << *it << " ";
		
	cout << endl;
	
	cout << "bidiractional iterator:" << endl; //just cycling from behind i guess
	for(it = end - 1; it >= start; --it)
		cout << *it << " ";
	
	cout << endl;
	
	cout << "Random access iterator" << endl;
	it = start + 7;
	cout << *it << " ";
	it -= 3;
	cout << *it << " ";
	it += 4;
	cout << *it << " ";
	cout << vi[5] << " ";
	cout << endl;
}


