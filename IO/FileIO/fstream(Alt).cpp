#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;

int main(int argc, char ** argv) {
	static int lineno = 0;
	static const char *filename = "test_iostream.txt";
	char buff[128]; cin.getline(buff, sizeof(buff));
	
	cout << "Writing to file: " << endl;
	ofstream ofile(filename);
	ofile << ++lineno << " " << buff << endl;
	ofile << ++lineno << " " << buff << endl;
	ofile << ++lineno << " " << buff << endl;
	ofile.close();
	
	static char buf[128];
	cout << "Reading the file" << endl;
	ifstream infile(filename);
	while(infile.good()) {
		infile.getline(buf, sizeof(buf));
		cout << buf << endl;
	}
	infile.close();
}


