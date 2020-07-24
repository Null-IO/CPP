#include <iostream>
#include <cstdio>
#include <fstream>
#include <iomanip> //for setfill() and setw()
using namespace std;

int main(int argc, char ** argv) {
	const char *FileName = "fstream_input.txt";
	size_t MaxSize = 256;
	char ibuff[MaxSize]; char obuff[MaxSize];
	string sArr[4] = {"First", "Second", "Third", "Fourth"};
	string *s = sArr;
	cin.getline(ibuff, MaxSize);
	
	cout << "Writing to file" << endl;
	fstream ofile;
	ofile.open(FileName, fstream::app);
	for(int i = 0; i < 4; i++) {
		ofile << *s << " Time writing " << ibuff << endl;
		s++;
	}
	
	ofile.close();
	
	fstream ifile;
	ifile.open(FileName, fstream::in);
	
	while(ifile.good()) {
		ifile.getline(obuff, MaxSize);
		cout << obuff << endl;
	}
	ifile.close();
}


