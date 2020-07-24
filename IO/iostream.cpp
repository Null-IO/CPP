#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main(int argc, char ** argv) {
	cout << "Prompt: ";
	char buf[128];
	cin.getline(buf, sizeof(buf));
	cout << "Input:" << buf << endl;
	
	cout << "-----------------------------------------------" << endl;
	
	int i = 42, i2 = 127, i3 = 5555;
	cout << "Default: " << i << " " << i2 << " " << i3 << endl;
	cout << "Hex: " << hex << i << " " << i2 << " " << i3 << endl;
	cout << "Hex with showbase: " << showbase << hex << i << " " << i2 << " " << i3 << endl;
	cout << "Octal with showbase: " << oct << i << " " << i2 << " " << i3 << endl;
	cout << "Default: " << noshowbase << dec << i << " " << i2 << " " << i3 << endl;
	
	cout << "-----------------------------------------------" << endl;
	
	double d1, d2, d3;
	d1 = 3.1415926534;
	d2 = 1234.5;
	d3 = 4.2e-10;
	cout << "Default: " << d1 << " " << d2 << " " << d3 << endl;
	cout << "Fixed: " << fixed << d1 << " " << d2 << " " << d3 << endl;
	cout << "scientific: " << scientific << d1 << " " << d2 << " " << d3 << endl;
	cout << "fixed(3): " << setprecision(3) << fixed << d1 << " " << d2 << " " << d3 << endl;
	cout << "scientific(7): " << setprecision(7) << scientific << d1 << " " << d2 << " " << d3 << endl;
	cout.unsetf(ios_base::floatfield); // sets everything to defaut
	cout << "Default: " << d1 << " " << d2 << " " << d3 << endl;
	
	cout << "-----------------------------------------------" << endl;
	
	string s1 = "This is a string";
	string s2 = "This is much longer string";
	string s3 = "Today's News: Big light in the sky slated to appear in east";
	
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	
	cout << setw(64) << right << s1 << endl;
	cout << setw(64) << right << s2 << endl;
	cout << setw(64) << right << s3 << endl;
	
	cout << setfill('-') << setw(64) << right << s1 << endl;
	cout << setfill('_') << setw(64) << right << s2 << endl;
	cout << left << s3 << endl;

}


