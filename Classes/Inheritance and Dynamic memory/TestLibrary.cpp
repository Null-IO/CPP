#include "Header.h"
#include <cstring>

baseDMA::baseDMA(const char* l, int r) {
	size_t len = strlen(l);
	label = new char[len + 1];
	strcpy_s(label, len + 1, l);
	rating = r;
}

baseDMA::baseDMA(const baseDMA& rs) {
	size_t len = strlen(rs.label);
	label = new char[len + 1];
	strcpy_s(label, len + 1, rs.label);
	rating = rs.rating;
}

baseDMA& baseDMA::operator = (const baseDMA& rs) {
	if (this == &rs)
		return *this;
	else {
		delete[] label;
		size_t len = strlen(rs.label);
		label = new char[len + 1];
		strcpy_s(label, len + 1, rs.label);
		rating = rs.rating;

		return *this;
	}
}

std::ostream& operator << (std::ostream& os, const baseDMA& rs) {
	os << "Label: " << rs.label << std::endl;
	os << "Rating: " << rs.rating << std::endl;
	return os;
}

baseDMA::~baseDMA() {
	delete[] label;
}

lacksDMA::lacksDMA(const char* c, const char* l, int r) : baseDMA(l, r) {
	size_t len = strlen(c);
	strcpy_s(color, len + 1, c);
}

lacksDMA::lacksDMA(const char* c, const baseDMA& rs) : baseDMA(rs) {
	size_t len = strlen(c);
	strcpy_s(color, len + 1, c);
}

std::ostream& operator << (std::ostream& os, const lacksDMA& ls) {
	os << (const baseDMA&)ls;
	os << "Color: " << ls.color << std::endl;
	return os;
}

hasDMA::hasDMA(const char* s, const char* l, int r) : baseDMA(l, r) {
	size_t len = strlen(s);
	style = new char[len + 1];
	strcpy_s(style, len + 1, s);
}

hasDMA::hasDMA(const char* s, const baseDMA& rs) : baseDMA(rs) {
	size_t len = strlen(s);
	style = new char[len + 1];
	strcpy_s(style, len + 1, s);
}

hasDMA::hasDMA(const hasDMA& hs) : baseDMA(hs) {
	size_t len = strlen(hs.style);
	style = new char[len + 1];
	strcpy_s(style, len + 1, hs.style);
}

hasDMA& hasDMA::operator = (const hasDMA& rs) {
	if (this == &rs)
		return *this;
	else {
		baseDMA::operator=(rs);
		delete[] style;
		size_t len = strlen(rs.style);
		style = new char[len + 1];
		strcpy_s(style, len + 1, rs.style);
		return *this;
	}
}

std::ostream& operator << (std::ostream& os, const hasDMA& hs) {
	os << (const baseDMA&)hs;
	os << "Style: " << hs.style << std::endl;
	return os;
}

hasDMA::~hasDMA() {
	delete[] style;
}