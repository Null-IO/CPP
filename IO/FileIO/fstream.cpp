#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv) {
	cout << "Input file name: ";
	string fName; cin >> fName;
	fName += ".txt";
	ofstream fout(fName.c_str());
	
	while (cin.get() != '\n');

	cout << "Enter file content (Max 50 chars)(to quit Enter + (Ctrl + Z)): ";
	char input[50];
	cin.get(input, 50, EOF);
	fout << input;
	fout.close();

	cout << "Here are the contents of " << fName << endl;
	ifstream fin(fName.c_str());
	char content[50];
	fin.get(content, 50, EOF);
	cout << content << endl;
	fin.close();
	
	return 0;
}