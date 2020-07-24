#include "Header.h"

std::ostream& operator << (std::ostream& os, const abstr_emp& e) {
	os << e.fname << std::endl;
	os << e.lname << std::endl;
	os << e.job << std::endl;

	return os;
}

void abstr_emp::ShowAll() const {
	std::cout << "Firstname: " << fname << std::endl;
	std::cout << "Lastname: " << lname << std::endl;
	std::cout << "Job: " << job << std::endl;
}

void abstr_emp::SetAll() {
	using std::string; using std::cout; using std::cin; using std::endl;
	string Nname, Nsurname, Njob;
	
	cout << "Enter new firstname: "; cin >> Nname; cout << endl;
	cout << "Enter new lastname: "; cin >> Nsurname; cout << endl;
	cout << "Enter new job: "; while (cin.get() != '\n'); 
	getline(cin, Njob); cout << endl;

	this->fname = Nname;
	this->lname = Nsurname;
	this->job = Njob;
}

void abstr_emp::writeAll(std::fstream& fstr) const {
	fstr << this->fname << std::endl;
	fstr << this->lname << std::endl;
	fstr << this->job << std::endl;
}

void abstr_emp::getAll(std::fstream& fstr) {
	fstr >> fname;
	fstr >> lname;
	fstr >> job;
}

abstr_emp::~abstr_emp() {} //Even though abstr_emp is abstarct, it still needs deconstructor

void employee::writeAll(std::fstream& fstr) const {
	fstr << classkind::Employee << std::endl;
	abstr_emp::writeAll(fstr);
}

void employee::getAll(std::fstream& fstr) {
	abstr_emp::getAll(fstr);
}

void manager::ShowAll() const {
	abstr_emp::ShowAll();
	std::cout << "In charge of: " << inchargeof << " people" << std::endl;
}

void manager::SetAll() {
	abstr_emp::SetAll();
	std::cout << "Input new inchargeof: "; 
	std::cin >> inchargeof; std::cout << std::endl;
}

void manager::writeAll(std::fstream& fstr) const {
	fstr << classkind::Manager << std::endl;
	abstr_emp::writeAll(fstr);
	fstr << this->inchargeof << std::endl;
}

void manager::getAll(std::fstream& fstr) {
	abstr_emp::getAll(fstr);
	fstr >> inchargeof;
}

void fink::ShowAll() const {
	abstr_emp::ShowAll();
	std::cout << "Reports to: " << reportsto << std::endl;
}

void fink::SetAll() {
	abstr_emp::SetAll();
	std::cout << "Input new reports to: ";
	std::getline(std::cin, this->reportsto); std::cout << std::endl;
}

void fink::writeAll(std::fstream& fstr) const {
	fstr << classkind::Fink << std::endl;
	abstr_emp::writeAll(fstr);
	fstr << this->reportsto << std::endl;
}

void fink::getAll(std::fstream& fstr) {
	abstr_emp::getAll(fstr);
	fstr.get(); char str[32]; fstr.get(str, 32);
	ReportsTo().assign(str);
}

void highfink::ShowAll() const {
	abstr_emp::ShowAll();
	std::cout << "In charge of: " << InChargeOf() << " people" << std::endl;
	std::cout << "Reports to: " << ReportsTo() << std::endl;
}

void highfink::SetAll() {
	abstr_emp::SetAll();
	std::cout << "Input new inchargeof: ";
	std::cin >> InChargeOf(); std::cout << std::endl;
	std::cout << "Input new reports to: "; std::cin.get();
	std::getline(std::cin, ReportsTo()); std::cout << std::endl;
}

void highfink::writeAll(std::fstream& fstr) const {
	fstr << classkind::Highfink << std::endl;
	abstr_emp::writeAll(fstr);
	fstr << this->InChargeOf() << std::endl;
	fstr << this->ReportsTo() << std::endl;
}

void highfink::getAll(std::fstream& fstr) {
	abstr_emp::getAll(fstr);
	fstr >> InChargeOf();
	fstr.get(); char str[32]; fstr.get(str, 32);
	ReportsTo().assign(str);
}