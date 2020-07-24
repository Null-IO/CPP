#include <iostream>
using namespace std;

class bad_arr : public exception {
private:
	string msg;
public:
	explicit bad_arr(const char* message) : msg(message) {};
	const char* Error_msg() const { return msg.c_str(); }
};

class Fenwick {
private:
	int* main_arr = nullptr;
	int* orig_arr = nullptr;
	size_t arr_size = 0;
public:
	explicit Fenwick(size_t size = 0, int* arr = nullptr);
	void create();
	const int sum( const int end) const;
	void debug();
	~Fenwick();
};

Fenwick::Fenwick(size_t size, int* arr) {
	if (arr == nullptr)
		throw bad_arr("Source Array is nullptr!");
	else {
		arr_size = size;
		main_arr = new int[size + __int64(1)] {};
		orig_arr = arr;
	}
	this->create();
}

void Fenwick::create() {
	for (int i = 0; i < arr_size; i++) {
		int indx = i + 1;

		while (indx <= arr_size) {
			main_arr[indx] += orig_arr[i];
			indx += (indx & -indx);
		}
	}
}

const int Fenwick::sum(const int end) const {
	int sum = 0;
	int idx = end + 1;

	while (0 < idx) {
		sum += main_arr[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

void Fenwick::debug() {
	cout << "Fenwick Arr: ";
	for (size_t i = 0; i < arr_size; i++)
		cout << main_arr[i] << " ";
}

Fenwick::~Fenwick() {
	delete[] main_arr;
}


int main(int argc, char** argv) {
	int arr[] = { 3, 2, -1, 6, 5, 4, -3, 3, 7, 2, 3 };
	size_t s = sizeof(arr) / sizeof(arr[0]);
	Fenwick f(s, arr);
	cout << f.sum(4) << endl; //range [0 - 4]
	cout << f.sum(8) - f.sum(5) << endl; //range ]5 - 8]

	return 0;
}