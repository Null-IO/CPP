#ifndef HEADER_H_
#define HEADER_H_

template<typename T> void counts();
template<typename T> void report(T&);

template<typename TT>
class HasFriendT {
private:
	TT item;
	static int ct;
public:
	HasFriendT(const TT& i) : item(i) { ct++; }
	friend void counts<TT>();
	friend void report<>(HasFriendT<TT>&);
	~HasFriendT() { ct--; }
};

#include "TestLibrary.h"

#endif