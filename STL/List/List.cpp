#include <iostream>
#include <cstdio>
#include <list>
using namespace std;

int main(int argc, char ** argv) {
	list<int> li1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	cout << "Size: " << li1.size() << endl;
	cout << "Front: " << li1.front() << endl;
	cout << "Back: " << li1.back() << endl << endl;
	
	cout << "push_back 47: " << endl;
	li1.push_back(47);
	cout << "Size: " << li1.size() << endl;
	cout << "Back: " << li1.back() << endl << endl;
	
	cout << "ranged-based for loop: " << endl;
	for(int v : li1)
		cout << v << " ";
	
	cout << endl << endl;
	
	list<int>::iterator it = li1.begin();
	while((*++it != 5) && it != li1.end());
	if(it != li1.end()) {
		cout << "Inserting 112" << endl;
		li1.insert(it, 112);
	}
	for(int v : li1)
		cout << v << " ";
	
	cout << endl;
	
	while((*++it != 7) && it != li1.end());
	if(it != li1.end()) {
		cout << "Erasing 7" << endl;
		li1.erase(it);
	}
	for(int v : li1)
		cout << v << " ";
	
	cout << endl << endl;
	
	list<int>::iterator it2 = it = li1.end();
	while(*++it != 112 && it != li1.end());
	while(*++it2 != 8 && it2 != li1.end());
	if(it != li1.end() && it2 != li1.end()) {
		cout << "Erasing from 112 to 8" << endl;
		li1.erase(it, it2);
	}
	for(int i : li1)
		cout << i << " ";
}


