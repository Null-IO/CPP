//needs proper command line!
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv) {
	if (argc == 1) {
		cout << "No arguments no cookie" << endl;
		exit(EXIT_FAILURE);
	}
	else {
		size_t total = 0; ifstream fin;
		for (size_t i = 1; i < argc; i++) {
			fin.open(argv[i]);
			
			if (!fin.is_open()) {
				cerr << "Could not open " << argv[i] << endl;
				fin.clear();
				continue;
			}
			size_t length = 0;

			char ch;
			while (fin.get(ch))
				length++;

			cout << length << " characters in " << argv[i] << endl;
			total += length;
			fin.clear();
			fin.close();
		}
		cout << total << " characters in all files" << endl;
	}
	
	return 0;
}