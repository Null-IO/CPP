#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int main(int argc, char ** argv) {
	map<string, string> m1 = {{"Zuka", "Son"}, {"Gio", "Son"}, {"Eka", "Mother"}, {"Zaza", "Father"}};
	
	cout << "Size of m1 " << m1.size() << endl;
	cout << "Gio is " << m1["Gio"] << endl;
	cout << "Zuka is " << m1.at("Zuka") << endl;
	cout << "Eka is " << m1.find("Eka")->second << endl;
	cout << endl;
	
	for(auto i : m1)
		cout << i.first << " is " << i.second << endl;
	
	cout << endl;
	
	cout << "Inserting element:" << endl;
	m1.insert({"Dito", "Friend"});
	cout << "size now is: " << m1.size() << endl;
	for(auto i : m1)
		cout << i.first << " is " << i.second << endl;
	
	cout << endl;
	
	cout << "Inserting duplicate:" << endl;
	auto rp = m1.insert({"Dito", "Friend"});
	if(!rp.second)
		cout << "Inserting failed" << endl;
	else
		cout << "Inserting succeeded" << endl;
	
	cout << "Finding and Erasing Element:" << endl;
	auto it = m1.find("Zuka");
	if(it != m1.end()) {
		cout << "found " << it->first << ":" << it->second << endl;
		m1.erase(it);
		cout << "Size now is " << m1.size() << endl;
	} else
		cout << "Not found" << endl;
	
	for(auto i : m1)
		cout << i.first << " is " << i.second << endl;
}


