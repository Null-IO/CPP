//Factorial works!!!
#include <iostream>
#include "std_lib_facilities.h"
using namespace std;

const char number = '8';
const char quit = 'q';
const char print = ';';

class primary_error{};
class input_error{};
class buffer_full{};
class bad_token{};
class divide_by_zero_error{};

class Token {
public:
	char kind;
	double value;
};

class Token_stream {
public:
	Token get();
	void putback(Token t);
private:
	bool full{false};
	Token buffer;
};

Token Token_stream::get() {
	if(full) {
		full = false;
		return buffer;
	}
	
	try {
		char ch;
		cin >> ch;
	
		switch(ch) {
			case print:
			case quit:
			case '(': case ')': case '+': case '-': case '*': case '/': case '!': case '%':
				return Token{ch};
			case '0': case '1': case '2': case '3': case '4':
			case '5': case '6': case '7': case '8': case '9':
			{
				cin.putback(ch);
				double val;
				cin >> val;
				return Token{number, val};
			}
			default:
				throw bad_token{};
		}
	} catch(bad_token) {
		cerr << "Bad Token!";
	}
}

void Token_stream::putback(Token t) {
	try {
		if(full) throw buffer_full{};
		buffer = t;
		full = true;
	
	} catch(buffer_full) {
		cerr << "Buffer is full!";
	}
}

Token_stream ts;
double expression();

double primary() {
	Token t = ts.get();
	
	try {
		while(true) {
			switch(t.kind) {
				case '(':
				{
					double d = expression();
					t = ts.get();
					if(t.kind != ')') throw input_error{};
					return d;
				}
				case number:
					return t.value;
				case '-':
					return -primary();
				case '+':
					return primary();
				default:
					throw primary_error{};
			} 
		}
	} catch(primary_error) {
		cerr << "Primary expected\n";
	}
}

int factorial() {
	int left = primary();
	Token t = ts.get();
	
	while(true) {
		switch(t.kind) {
			case '!':
			{	
				if(left == 1) {
					left = 0;
					t = ts.get();
				}
				else {
					int a = 1;
					for(int i = left; i > 0; i--) 
						a *= i;
				
					left = a;
					t = ts.get();
					break;
				}
			}
			default:
				ts.putback(t);
				return left;
		}
	}
}

double term() {
	double left = factorial();
	Token t = ts.get();
	
	try {
		while(true) {
			switch(t.kind) {
				case '*':
					left *= factorial();
					t = ts.get();
					break;
				case '/':
				{
					double d = factorial();
					if(d == 0) throw divide_by_zero_error{};
					left /= d;
					t = ts.get();
					break;
				}
				case '%':
				{
					double d = factorial();
					if(d == 0) throw divide_by_zero_error{};
					left = fmod(left, d);
					t = ts.get();
					break;		
				}
				default:
					ts.putback(t);
					return left;
				}
			}
		} catch(divide_by_zero_error) {
			cerr << "Can't divide by zero!";
		}
}

double expression() {
	double left = term();
	Token t = ts.get();
	
	while(true) {
		switch(t.kind) {
			case '+':
				left += term();
				t = ts.get();
				break;
			case '-':
				left -= term();
				t = ts.get();
				break;
			default:
				ts.putback(t);
				return left;
		}
	}
}

void calculate() {
	double val = 0;
		while(cin) {
			cout << "> ";
			Token t = ts.get();
			
			while(t.kind == print) t = ts.get();
			
			if(t.kind == quit)
				return;
				
			ts.putback(t);
			cout << "= " << expression() << '\n';
		}
}

main() {
	try {
		calculate();
		return 0;
	} catch(exception& e) {
		cerr << e.what();
		return 1;
	
	} catch(...) {
		cerr << "Unknown Error!";
		return 2;
	}
}

