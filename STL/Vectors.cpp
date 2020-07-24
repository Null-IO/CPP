#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char ** argv) {
	vector<int> v1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	cout << "Size: " << v1.size() << endl;
	cout << "Front: " << v1.front() << endl;
	cout << "Back: " << v1.back() << endl;
	
	vector<int>::iterator itbegin = v1.begin();
	auto itend = v1.end(); // vector<int>::iterator itend = v1.end(); is the same! auto is easier
	for(auto it = itbegin; it < itend; ++it)
		cout << v1.begin();
	
	cout << endl;
	
	cout << "Element 5: " << v1.at(5) << endl;
	cout << "Element 5(x2): " << v1[5] << endl;
	
	cout << "Ranged-based for loop: " << endl;
	
	for(int &i : v1)
		cout << i << " ";
		
	cout << endl;
	
	cout << "Inserting 42 at begin + 5: " << endl;
	v1.insert(v1.begin() + 5, 42);
	cout << "Size: " << v1.size() << endl;
	cout << "v1[5]: " << v1[5] << endl;
	
	cout << "Erasing 42 at begin + 5: " << endl;
	v1.erase(v1.begin() + 5);
	cout << "Size: " << v1.size() << endl;
	cout << "v1[5]: " << v1[5] << endl;
	
	cout << "Pushing 42 at back " << endl;
	v1.push_back(42);
	cout << "Size: " << v1.size() << endl;
	cout << "v1 Back: " << v1.back() << endl;
	
	//Pre c++11 vector
	const static size_t MaxSize = 10;
	int ia[MaxSize] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	cout << "Vector from C-array: " << endl;
	vector<int> v2(ia, ia + MaxSize);
	for(int &i : v2)
		cout << i << " ";
	
	cout << endl;
	
	cout << "vector of string:" << endl;
	vector<string> vs = {"One", "Two", "Three", "Four", "Five"};
	for(string &s : vs)
		cout << s << " ";
}


