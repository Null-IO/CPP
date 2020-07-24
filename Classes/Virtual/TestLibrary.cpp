#include <iostream>
#include "Header.h"
using std::cout; using std::endl;

typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;

format setformat() {
	return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void restore(format f, precis p) {
	cout.setf(f, std::ios_base::floatfield);
	cout.precision(p);
}

Brass::Brass(const string& s, long an, double bal) {
	fullname = s;
	acctNum = an;
	balance = bal;
}

void Brass::Deposit(double amt) {
	if (amt < 0)
		cout << "Negative amount in not allowed!" << endl;
	else
		balance += amt;
}

void Brass::withdraw(double amt) {
	format initialState = setformat();
	precis prec = cout.precision(2);

	if(amt < 0)
		cout << "Negative amount in not allowed!" << endl;
	else if(amt <= balance)
		balance -= amt;
	else
		cout << "Withdrawal amount of $" << amt
		<< " exceeds your balance.\n"
		<< "Withdrawal canceled.\n";

	restore(initialState, prec);
}

double Brass::Balance() const {
	return balance;
}

void Brass::ViewAcct() const {
	format initialState = setformat();
	precis prec = cout.precision(2);
	cout << "Client: " << fullname << endl;
	cout << "Account Number: " << acctNum << endl;
	cout << "Balance: $" << balance << endl;
	restore(initialState, prec);
}

BrassPlus::BrassPlus(const string& s, long an, double bal, double ml, double r) : Brass(s, an, bal) {
	maxloan = ml;
	rate = r;
	debt = 0.0;
}

BrassPlus::BrassPlus(const Brass& ba, double ml, double r) : Brass(ba) {
	maxloan = ml;
	rate = r;
	debt = 0.0;
}

void BrassPlus::ViewAcct() const {
	format initialState = setformat();
	precis prec = cout.precision(2);
	
	Brass::ViewAcct();
	cout << "Maximum loan: $" << maxloan << endl;
	cout << "Owed to bank: $" << debt << endl;
	cout.precision(3);
	cout << "Loan Rate: " << 100 * rate << "%\n";
	
	restore(initialState, prec);
}

void BrassPlus::Withdraw(double amt) {
	format initialState = setformat();
	precis prec = cout.precision(2);

	double bal = Balance();
	if (amt <= bal)
		Brass::withdraw(amt);
	else if (amt <= bal + maxloan - debt) {
		double advance = amt - bal;
		debt += advance * (1.0 + rate);
		cout << "Bank advance: $" << advance << endl;
		cout << "Finance charge: $" << advance * rate << endl;
		Deposit(advance);
		Brass::withdraw(amt);
	}
	else
		cout << "Credit limit exceeded. Transaction cancelled" << endl;

	restore(initialState, prec);
}