#ifndef HEADER_H_
#define HEADER_H_
#include <iostream>

class baseDMA {
private:
	char* label;
	int rating;
public:
	baseDMA(const char* l = "null", int r = 0);
	baseDMA(const baseDMA& rs);
	baseDMA& operator = (const baseDMA& rs);
	friend std::ostream& operator << (std::ostream& os, const baseDMA& rs);
	virtual ~baseDMA();
};

class lacksDMA : public baseDMA {
private:
	enum {COL_LEN = 40};
	char color[COL_LEN];
public:
	lacksDMA(const char* c = "blank", const char* l = "null", int r = 0);
	lacksDMA(const char* c, const baseDMA& rs);
	friend std::ostream& operator << (std::ostream& os, const lacksDMA& ls);
};

class hasDMA : public baseDMA {
private:
	char* style;
public:
	hasDMA(const char* s = "none", const char* l = "null", int r = 0);
	hasDMA(const char* s, const baseDMA& rs);
	hasDMA(const hasDMA& hs);
	hasDMA& operator = (const hasDMA& rs);
	friend std::ostream& operator << (std::ostream& os, const hasDMA& hs);
	~hasDMA();
};

#endif