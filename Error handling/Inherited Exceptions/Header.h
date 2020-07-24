#ifndef HEADER_H_
#define HEADER_H_
#include <cstring>
#include <iostream>

class BadDims2D {
private:
	double length;
	double width;
public:
	BadDims2D(double l, double w) : length(l), width(w) {};
	virtual void ErrorMsg() const;
	~BadDims2D() {};
};

class BadDims3D : public BadDims2D {
private:
	double height;
public:
	BadDims3D(double l, double w, double h) : BadDims2D(l, w), height(h) {};
	void ErrorMsg() const;
	~BadDims3D() {};
};

inline void BadDims2D::ErrorMsg() const {
	double Dims[2] = { length, width };
	for (int i = 0; i < 2; i++)
		if (Dims[i] <= 0.0)
			std::cout << "Bad dimension: " << Dims[i] << std::endl;
		
}

inline void BadDims3D::ErrorMsg() const {
	BadDims2D::ErrorMsg();
	if (height <= 0.0)
		std::cout << "Bad dimension: " << height << std::endl;
}

#endif // !HEADER_H_