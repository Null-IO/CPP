#include <iostream>
#include <cstdio>
#include <cstdint>
using namespace std;

template <typename T>
class Stack {
private:
	static const int _maxSize = 256;
	static const int _defaultSize = 4;
	int _size, _top;
	int _bottom;
	T * stackArr;
public:
	explicit Stack(int s = _defaultSize);
	~Stack() {delete[] stackArr;};
	bool isFull() { return _top >= _size - 1; }
	bool isEmpty() { return _top < 0; }
	bool isEmptyBott() {return _bottom >= _size - 1; }
	int getSize() const { return _size; }
	int getTop() const { return _top; }
	T & push(const T & i);
	T & pop();
	T & popBott();
	
};

template <typename T>
Stack<T>::Stack(int s) {
	if(s <= _maxSize || s >= 1) {
		_size = s;
		stackArr = new T[_size];
		_top = -1;
		_bottom = -1;
	}
}

template <typename T>
T & Stack<T>::push(const T & i) {
	if(!isFull()) 
		return stackArr[++_top] = i;
}

template <typename T>
T & Stack<T>::pop() {
	if(!isEmpty())
		return stackArr[_top--];
}

template <typename T>
T & Stack<T>::popBott() {
	if(!isEmptyBott())
		return stackArr[++_bottom];
}

int main(int argc, char ** argv) {
	Stack<int> s1(42);
	
	for(int i = 0; i < s1.getSize(); i++) {
		static uint64_t a = 1;
		static uint64_t b = 2;
		uint64_t c = a + b;
		
		s1.push(c);
		
		a = b;
		b = c;
	}
	
	
	while(!s1.isEmpty())
		cout << "FILO stack popped: " << s1.pop() << endl;
		
	Stack<string> s2(4);
	
	for(const char * c : {"Zuka", "Vaja", "Ako", "Gurama"})
		s2.push(c);
	
	while(!s2.isEmptyBott())
		cout << "FIFO stack popped: " << s2.popBott() << endl;
		
}


