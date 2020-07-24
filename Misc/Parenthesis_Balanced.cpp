#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

bool balanced(string s) {
	stack<char> st; char ch;
	
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
			st.push(s[i]);
			continue;
		}
		
		if(st.empty())
			return false;
		
		switch(s[i]) {
			case ')':
				ch = st.top();
				st.pop();
				if(ch == '{' || ch == '[')
					return false;
				break;
			case '}':
				ch = st.top();
				st.pop();
				if(ch == '(' || ch == '[')
					return false;
				break;
			case ']':
				ch = st.top();
				st.pop();
				if(ch == '(' || ch == '{')
					return false;
				break;
		}
	}
	cout << st.size() << endl;
	return (st.empty());
}

int main(int argc, char ** argv) {
	string s; cin >> s;
	if(balanced(s))
		puts("Balanced");
	else
		puts("Nope");
}


