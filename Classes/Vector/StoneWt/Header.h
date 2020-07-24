#ifndef HEADER_H_
#define HEADER_H_

class Stonewt
{
public:
	enum MODE{Stone, Pounds};
private:
	enum { Lbs_per_stn = 14 }; // pounds per stone
	MODE mode;
	int stone; // whole stones
	double pds_left; // fractional pounds
	double pounds; // entire weight in pounds
public:
	Stonewt(double lbs, MODE Mode = Stone); // constructor for double pounds
	Stonewt(); // default constructor
	friend std::ostream& operator <<(std::ostream& os, const Stonewt& st);
	friend Stonewt operator +(const Stonewt& st, const Stonewt& st2);
	friend Stonewt operator -(const Stonewt& st, const Stonewt& st2);
	friend Stonewt operator *(const Stonewt& st, const Stonewt& st2);
	friend bool operator <(const Stonewt& st, const Stonewt& st2);
	~Stonewt();
};
#endif

