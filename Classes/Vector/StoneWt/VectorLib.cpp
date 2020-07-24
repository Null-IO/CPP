#include <iostream>
#include "Header.h"
using std::endl;

Stonewt::Stonewt(double lbs, MODE Mode)
{
	stone = int(lbs) / Lbs_per_stn; // integer division
	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
	mode = Mode;
}
// construct Stonewt object from stone, double values
/*
Stonewt::Stonewt(int stn, double lbs)
{
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn + lbs;
}
*/
Stonewt::Stonewt() // default constructor, wt = 0
{
	stone = pounds = pds_left = 0;
	mode = Stone;
}

std::ostream& operator <<(std::ostream& os, const Stonewt& st) {
	if (st.mode == Stonewt::MODE::Stone)
		os << st.stone << " " << st.pds_left << endl;
	else if (st.mode == Stonewt::MODE::Pounds)
		os << st.pounds << endl;

	return os;
}

Stonewt operator +(const Stonewt& st, const Stonewt& st2) {
	Stonewt newSt = Stonewt(st.pounds + st2.pounds);
	return newSt;
}

Stonewt operator -(const Stonewt& st, const Stonewt& st2) {
	Stonewt newSt;

	if (st.pounds - st.pounds < 0)
		newSt = Stonewt();
	else
		newSt = Stonewt(st.pounds - st2.pounds);

	return newSt;
}

Stonewt operator *(const Stonewt& st, const Stonewt& st2) {
	Stonewt newSt = Stonewt(st.pounds * st2.pounds);

	return newSt;
}

bool operator <(const Stonewt& st, const Stonewt& st2) {
	if (st.pounds > st2.pounds)
		return true;

	return false;
}

Stonewt::~Stonewt() // destructor
{
}


