#include <iostream>
#include <thread>
#include <stdexcept>
#include <stack>
#include <mutex>
#include <memory>
#include <ctime>
#include <vector>
using namespace std;

class emptyStack : public length_error {
public:
	explicit emptyStack(const string& s = "Stack is empty") : length_error(s) {};
	virtual ~emptyStack() {};
};

template<typename T>
class threadSafeStack {
private:
	stack<T> data;
	mutable mutex m; //()const member function can modify "mutable"
public:
	threadSafeStack() {}
	threadSafeStack(const threadSafeStack& tss) {
		lock_guard<mutex> lock(m);
		data = tss;
	}
	threadSafeStack& operator = (const threadSafeStack&) = delete;
	
	void push(T newValue) {
		lock_guard<mutex> lock(m);
		data.push(move(newValue));
	}
	
	shared_ptr<T> pop() { //Doesn't compile with this
		lock_guard<mutex> lock(m);
		if (data.empty())
			throw emptyStack();

		const shared_ptr<T> res(make_shared<T>(data.top()));
		data.pop();
		
		return res;
	} 

	void pop(vector<T>& v) {
		lock_guard<mutex> lock(m);
		if (data.empty())
			throw emptyStack();

		v.push_back(data.top());
		data.pop();
	}
	bool empty() const {
		lock_guard<mutex> lock(m);
		return data.empty();
	}
};

int main(int argc, char** argv) {
	srand(time(NULL));
	threadSafeStack<int> tss;
	vector<thread> vec;
	vector<int> data;
	
	for (size_t i = 0; i < thread::hardware_concurrency() / 2; i++)
		vec.emplace_back(&threadSafeStack<int>::push, &tss, rand() % 50);
			
	for (size_t i = thread::hardware_concurrency() / 2; i < thread::hardware_concurrency() - 1; i++)
		vec.emplace_back(static_cast<void(threadSafeStack<int>::*)(vector<int>&)>(&threadSafeStack<int>::pop), &tss, ref(data)); //tells the compiler to use void pop() overloaded function, because compiler can't deduce at compile time

	vec.emplace_back(static_cast<shared_ptr<int>(threadSafeStack<int>::*)()>(&threadSafeStack<int>::pop), &tss); //tells the compiler to use shared_ptr pop() overloaded function

	for (auto& i : vec)
		i.join();

	for (auto& i : data)
		cout << i << endl;
	
	return 0;
}