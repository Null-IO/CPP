#ifndef HEADER_H_
#define HEADER_H_

template<typename T>
class HasFriend {
private:
	T item;
	static int ct;
public:
	HasFriend(const T& i) : item(i) { ct++; }
	friend void counts();
	friend void reports(HasFriend<T>&);
	~HasFriend() { ct--; }
};

#include "TestLibrary.h"

#endif