#include <iostream>
#include <cstdio>
#include <set>
#include <time.h>
using namespace std;

int main(int argc, char ** argv) {
	set<int> s1; set<string> s2 = {"Zuka", "Eka", "Gio", "Zaza"};
	srand(time(NULL));
	
	for(int i = 0; i < 10; i++)
		s1.insert(rand() % 100);
	
	cout << "s1 size is: " << s1.size() << endl;
	cout << "s2 size is: " << s2.size() << endl;
	
	cout << "s1 is:" << endl;
	for(int i : s1)
		cout << i << " ";
	
	cout << endl << endl;
	
	cout << "s2 is:" << endl;
	for(string i : s2)
		cout << i << " ";
	
	cout << endl << endl;
	
	set<string>::iterator si = s2.find("Zuka");
	if(si != s2.end()) {
		cout << "Erasing " << *si << endl;
		s2.erase(si);
	} else
		cout << "Not Found" << endl;
	
	cout << endl;
	
	cout << "s2 now is:" << endl;
	for(string i : s2)
		cout << i << " ";
	
	cout << endl << endl;
	
	auto rp = s1.insert(69);
	if(rp.second) {
		cout << "Insert succeeded" << endl;
		
		cout << "s1 now is:" << endl;
		for(int i : s1)
			cout << i << " ";
	}
	else
		cout << "Insert Failed" << endl;
}


