#include "Header.h"
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <cctype>

Planet::Planet(const char* _name, const double _population, const double _g) : population(_population), g(_g), ct(0) {
	strcpy_s(name, strlen(_name) + 1, _name);
}

std::ostream& operator << (std::ostream& os, const Planet& p) {
	using std::setw; using std::setprecision; using std::endl;

	os << std::fixed;
	os << std::setw(20) << p.name << ": "
		<< std::setprecision(0) << setw(12) << p.population
		<< setprecision(2) << setw(6) << p.g << endl;

	return os;
}

std::istream& operator >> (std::istream& is, Planet& p) {
	using std::cout;
	
	cout << "Enter planet name: ";
	is.get(p.name, 20);
	p.eatline();
	cout << "Enter planetary population: ";
	is >> p.population;
	cout << "Enter planet's acceleration of gravity: ";
	is >> p.g;
	p.eatline();

	return is;
}

Binary_Writer::Binary_Writer(const char* _filename) : filename(_filename) {
	fstr.open(filename, std::ios_base::in | std::ios_base::out | std::ios_base::binary);

	if (fstr.is_open())
		std::cout << filename << " successfully opened..." << std::endl;
	else {
		std::ofstream tmp(filename, std::ios_base::binary);
		std::cout << filename << " is absent so creating file now" << std::endl;
		tmp.close();

		fstr.open(filename, std::ios_base::in | std::ios_base::out | std::ios_base::binary);
		
		if (fstr.fail()) {
			std::cerr << filename << " Couldn't be opened" << std::endl;
			exit(EXIT_FAILURE);
		}
	}
	this->get_filesize();
	this->UI();
}

void Binary_Writer::get_filesize() {
	if (fstr.is_open()) {
		fstr.seekg(0, std::ios::end);
		filesize = fstr.tellg();
		fstr.seekg(0); //reset file pointer
	}
	else {
		std::cerr << filename << " isn't opened" << std::endl;
		exit(EXIT_FAILURE);
	}
}

void Binary_Writer::read(const std::streampos pos) {
	using std::cout; using std::endl;
	int ln = 0;
	if (filesize == 0) {
		cout << "File is Empty input data" << endl;
		std::cin >> pl;
		fstr.write((char*)&pl, sizeof(pl));
		this->get_filesize();
		this->clearEOF();
	}
	if (pos != -1) {
		if (pos >= 0 && pos < (filesize / sizeof(pl))) {
			std::streampos p = pos * sizeof(pl);
			fstr.seekg(p);

			if (fstr.fail()) {
				cout << "Seek failed!" << endl;
				exit(EXIT_FAILURE);
			}
			else {
				cout << "Reading from " << p << " byte" << endl;
				while (fstr.read((char*)&pl, sizeof(pl)))
					cout << pl;

				fstr.seekg(0);
			}
		}
		else {
			cout << "Invalid seek position" << endl;
			exit(EXIT_FAILURE);
		}
	}
	else {
		cout << "Here are the current contents of a " << filename << endl;
		while (fstr.read((char*)&pl, sizeof(pl)))
			cout << ln++ << pl;
	}
	this->clearEOF();
}

void Binary_Writer::write(const std::streampos pos) {
	using std::cout; using std::cin; using std::endl; using std::ios_base;
	
	if (pos != -1) {
		if (pos >= 0 && pos < (filesize / sizeof(pl))) {
			std::streampos p = pos * sizeof(pl);
			fstr.seekg(p);

			cout << "Modifying current selection" << endl;
			fstr.read((char*)&pl, sizeof(pl));
			cout << pl;

			cin >> pl;
			fstr.seekp(p);
			fstr.write((char*)&pl, sizeof(pl));

			fstr.seekg(0); fstr.seekp(0);
		
		} else {
			cout << "Invalid seek position" << endl;
			exit(EXIT_FAILURE);
		}
	}
	else {
		cout << "Appending data" << endl;
		std::ofstream app(filename, ios_base::out | ios_base::app | ios_base::binary);
		cin >> pl;
		app.write((char*)&pl, sizeof(pl));
		app.close();
	}
	this->get_filesize();
	this->clearEOF();
	this->read();
}

void Binary_Writer::erase(const std::streampos pos) {
	using std::cout; using std::endl; using std::ios_base;
	
	if (pos >= 0 && pos < (filesize / sizeof(pl))) {
		Planet tmp; std::ofstream otmp("tmp.dat", std::ios_base::binary);
		std::streampos p = pos * sizeof(pl);
		
		fstr.seekg(p);
		if (fstr.fail()) {
			cout << "Seek failed" << endl;
			exit(EXIT_FAILURE);
		}
		fstr.read((char*)&tmp, sizeof(pl));
		cout << tmp;
		fstr.seekg(0); //reset

		while (fstr.read((char*)&pl, sizeof(pl))) {
			if (strcmp(pl.name, tmp.name) == 0)
				continue;
			
			otmp.write((char*)&pl, sizeof(pl));
		}
		otmp.close();
		fstr.close();
		if (!remove(filename) && rename("tmp.dat", filename))
			cout << "Line successfully erased" << endl;
		
		fstr.open(filename, std::ios_base::in | std::ios_base::out | std::ios_base::binary);
		if (fstr.fail()) {
			cout << "Reopening of " << filename << " failed" << endl;
			exit(EXIT_FAILURE);
		}

		this->get_filesize();
		this->read();
	}
	else {
		cout << "Invalid seek position" << endl;
		exit(EXIT_FAILURE);
	}
}

void Binary_Writer::UI() {
	using std::cout; using std::endl; using std::cin;
	cout << "Welcome to Binary planet writer, enter:" << endl;
	cout << "0 --> read mode; 1 --> write mode; 2 --> erase mode(q to quit)" << endl;
	char ch = '0';

	while (ch != 'q') {
		cout << "Enter mode: ";
		cin >> ch;

		switch (ch) {
		case '0': {
			cout << endl << "Reading mode engadged" << endl;
			cout << "Do you want to specify reading position? -> ";
			char ans; cin >> ans; cout << endl;

			if (ans == 'Y' || ans == 'y') {
				cout << "Please enter position: ";
				int pos = 0; cin >> pos;
				this->read(static_cast<std::streampos>(pos));
			}
			else
				this->read();

			cout << endl;
			break;
		}
		case '1': {
			cout << endl << "Writing mode engadged" << endl;
			cout << "Do you want to specify writing position? -> ";
			char ans; cin >> ans; this->eatline(); cout << endl;

			if (ans == 'Y' || ans == 'y') {
				cout << "Please enter position: ";
				int pos = 0; cin >> pos; this->eatline();
				this->write(static_cast<std::streampos>(pos));
			}
			else
				this->write();

			cout << endl;
			break;
		}
		case '2': {
			cout << endl << "Erasing mode engadged" << endl;
			cout << "Please enter erase position -> ";

			int pos = 0; cin >> pos; this->eatline();
			this->erase(static_cast<std::streampos>(pos));
			
			cout << endl;
			break;
		}
		default:
			break;
		}
	}
	cout << "Done" << endl;
}