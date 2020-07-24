#pragma once

#include "Header.h"
#include <iostream>
using std::cout; using std::endl;

template<typename T>
int HasFriendT<T>::ct = 0;

template<typename T>
void counts() {
	cout << "template size: " << sizeof(HasFriendT<T>) << "; ";
	cout << "template counts(): " << HasFriendT<T>::ct << endl;
}

template<typename T>
void report(T& hf) {
	cout << hf.item << endl;
}
