#include <iostream>
#include <cstdlib>
#include <string>
#include <new>
using namespace std;
const int BUFF = 512;

class justTesting {
private:
	string words;
	int numbers;
public:
	justTesting(const string& s = "just Testing", int n = 0) { words = s; numbers = n; cout << words << " constructed!" << endl; }
	~justTesting() { cout << words << " deconstructed!" << endl; }
	void Show() const { cout << words << ", " << numbers << endl; }
};

int main(int argc, char** argv) {
	char* buffer = new char[BUFF];
	justTesting* pc1, * pc2;
	
	pc1 = new (buffer) justTesting;
	pc2 = new justTesting("Heap1", 20);
	
	cout << "Memory block addresses:\n" << "buffer: " << (void*)buffer << " heap: " << pc2 << endl;
	
	cout << "Memory contents: " << endl;
	cout << pc1 << ": "; pc1->Show();
	cout << pc2 << ": "; pc2->Show();

	justTesting* pc3, * pc4;
	pc3 = new (buffer + sizeof(justTesting)) justTesting("Bad idea", 6);
	pc4 = new justTesting("Heap2", 10);

	cout << "Memory contents: " << endl;
	cout << pc3 << ": "; pc3->Show();
	cout << pc4 << ": "; pc4->Show();

	delete pc2; delete pc4;
	pc3->~justTesting(); //deleting order matters!!!
	pc1->~justTesting(); //delete like stack!!!
	delete[] buffer;
	cout << "Done!" << endl;
	
	return 0;
}
