#ifndef HEADER_H_
#define HEADER_H_
#include <iostream>
#include <fstream>

class Planet {
public:
	char name[20] {}; //string caution: you don’t copy the string data, you just copy the address of where the string was stored. When you run the program again, that address is meaningless.
	double population = 0;
	double g = 0.0;
	int ct = 0;
public:
	Planet(const char* _name = "", const double _population = 0.0, const double _g = 0.0);
	friend std::ostream& operator << (std::ostream& os, const Planet& p);
	friend std::istream& operator >> (std::istream& is, Planet& p);
	inline void eatline() { while (std::cin.get() != '\n'); }
};

class Binary_Writer {
private:
	const char* filename;
	std::fstream fstr;
	Planet pl;
	std::streampos filesize;
	void get_filesize();
	inline void clearEOF() { if (fstr.eof()) fstr.clear(); }
	inline void eatline() { while (std::cin.get() != '\n'); }
public:
	Binary_Writer(const char* _filename);
	void UI();
	void read(const std::streampos pos = -1);
	void write(const std::streampos pos = -1);
	void erase(const std::streampos pos);
};

#endif // !HEADER_H_