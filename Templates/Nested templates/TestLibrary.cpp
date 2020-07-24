#include "Header.h"

template <typename T>
	template <typename V>
	class Beta<T>::Hold {
		private:
		V val;
	public:
		Hold(V v = 0) : val(v) {};
		void show() const { cout << val << endl; }
		V value() const { return val; }
	};

template <typename T>
	template <typename U>
	U Beta<T>::blab(U u, T t) {
		return (n.value() + q.value()) * u / t;
	}