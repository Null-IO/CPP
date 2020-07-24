#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <functional>

template <typename T>
T use_f(T v, std::function<T(T)> f) { //wraps Fq & Fp to return double, thus reducing number of instantiations.(otherwise F becomes type Fq not double(see Header.h))
	static int count = 0;
	count++;
	std::cout << " use_f count = " << count
		<< ", &count = " << &count << std::endl;
	return f(v); //double(double) call signature
}

class Fp {
private:
	double z_;
public:
	Fp(double z = 1.0) : z_(z) {}
	double operator()(double p) { return z_ * p; }
};

class Fq {
private:
	double z_;
public:
	Fq(double z = 1.0) : z_(z) {}
	double operator()(double q) { return z_ + q; }
};

#endif // !HEADER_H_