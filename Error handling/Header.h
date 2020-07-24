#ifndef HEADER_H_
#define HEADER_H_
#include <iostream>

class bad_hmean {
private:
	double v1;
	double v2;
public:
	bad_hmean(double d1 = 0.0, double d2 = 0.0) : v1(d1), v2(d2) {};
	void ErrMsg() const;
};

inline void bad_hmean::ErrMsg() const {
	std::cout << "hmean(" << v1 << ", " << v2 << "): "
		<< "invalid arguments: a = -b\n";
}

class bad_gmean {
public:
	double v1;
	double v2;
	bad_gmean(double a = 0, double b = 0) : v1(a), v2(b) {}
	const char* mesg();
};

inline const char* bad_gmean::mesg()
{
	return "gmean() arguments should be >= 0\n";
}

#endif // !HEADER_H_