#pragma once
#include "Header.h"
#include <iostream>
using std::cout; using std::endl;

template<typename T>
int HasFriend<T>::ct = 0;

void counts() {
	cout << "HasFriend<int> ct: " << HasFriend<int>::ct << endl;
	cout << "HasFriend<int> ct: " << HasFriend<double>::ct << endl;
}

void reports(HasFriend<int>& hf) {
	cout << "HasFriend<int>: " << hf.item << endl;
}

void reports(HasFriend<double>& hf) {
	cout << "HasFriend<double>: " << hf.item << endl;
}