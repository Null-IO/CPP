#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
using std::cout;
using std::endl;

template<typename T>
class Beta {
private:
	template<typename V>
	class Hold;
	Hold<T> q;
	Hold<int> n;
public:
	Beta(T t, int i) : q(t), n(i) {};
	template<typename U>
	U blab(U u, T t);
	void show() const { q.show(); n.show(); }
};

#endif