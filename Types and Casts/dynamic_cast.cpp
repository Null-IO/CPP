#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>
using std::cout; using std::endl;

class Grand {
private:
	int hold;
public:
	Grand(int h = 0) : hold(h) {};
	virtual void Speak() const { cout << "I am a Grand class!" << endl; }
	virtual int Value() const { return hold; }
};

class Superb : public Grand {
public:
	Superb(int h = 0) : Grand(h) {};
	void Speak() const { cout << "I am a Superb class!" << endl; }
	virtual void Say() const { cout << "I hold the superb value of " << Value() << "!" << endl; }
};

class Magnificent : public Superb {
private:
	char ch;
public:
	Magnificent(char c, int h) : Superb(h), ch(c) {};
	void Speak() const { cout << "I am a Magnificent class!!!" << endl; }
	void Say() const { cout << "I hold the character " << ch << " and the integer " << Value() << "!" << endl; }
};

Grand* GetOne() {
	Grand* p = nullptr;
	switch (std::rand() % 3) {
	case 0:
		p = new Grand(std::rand() % 100);
		break;
	case 1:
		p = new Superb(std::rand() % 100);
		break;
	case 2:
		p = new Magnificent(std::rand() % 26 + 'A', std::rand() % 100);
		break;
	}
	return p;
}

int main(int argc, char** argv) {
	srand(time(0));
	Grand* pg = nullptr;
	Superb* ps = nullptr;
	for (int i = 0; i < 5; i++) {
		pg = GetOne();
		cout << "Now processing type " << typeid(*pg).name() << endl;
		pg->Speak();

		if (ps = dynamic_cast<Superb*>(pg))
			ps->Say();
		if(typeid(Magnificent) == typeid(*pg))
			cout << "Yes, you're really magnificent.\n";
	}
	return 0;
}