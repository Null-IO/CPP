#ifndef HEADER_H_
#define HEADER_H_
#include <string>
using std::string;

class Brass {
private:
	string fullname;
	long acctNum;
	double balance;
public:
	Brass(const string& s = "nullBody", long an = -1, double bal = 0.0);
	void Deposit(double amt);
	virtual void withdraw(double amt);
	double Balance() const;
	virtual void ViewAcct() const;
	virtual ~Brass() {};
};

class BrassPlus : public Brass {
private:
	double maxloan;
	double rate;
	double debt;
public:
	BrassPlus(const string& s = "nullBody", long an = -1, double bal = 0.0, double ml = 500, double r = 0.11125);
	BrassPlus(const Brass& ba, double ml = 500, double r = 0.11125);
	virtual void ViewAcct() const;
	virtual void Withdraw(double amt);
	void ResetMax(double m) { maxloan = m; }
	void ResetRate(double r) { rate = r; }
	void ResetDebt() { debt = 0; }
};

#endif