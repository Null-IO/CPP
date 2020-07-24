#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

const int limit = 5;

void File_it(ostream& os, double fo, const double fe[], int n);

int main(int argc, char** argv) {
	ofstream fout;
	const char* fn = "ep-data.txt";
	fout.open(fn);
	
	if (!fout.is_open())
	{
		cout << "Can't open " << fn << ". Bye.\n";
		exit(EXIT_FAILURE);
	}
	
	double objective;
	cout << "Enter the focal length of your "
		"telescope objective in mm: ";
	cin >> objective;
	double eps[limit];
	cout << "Enter the focal lengths, in mm, of " << limit
		<< " eyepieces:\n";
	for (int i = 0; i < limit; i++)
	{
		cout << "Eyepiece #" << i + 1 << ": ";
		cin >> eps[i];
	}
	File_it(fout, objective, eps, limit);
	File_it(cout, objective, eps, limit);
	cout << "Done\n";

	return 0;
}
void File_it(ostream& os, double fo, const double fe[], int n) {
	ios_base::fmtflags initial;
	initial = os.setf(ios_base::fixed);
	os.precision(0);
	os << "Focal length of objective: " << fo << " mm" << endl;
	os.setf(ios::showpoint);
	os.precision(1);
	os.width(12);
	os << "magnification" << endl;

	for (int i = 0; i < n; i++) {
		os.width(12);
		os << fe[i];
		os.width(15);
		os << int(fo / fe[i] + 0.5) << endl;
	}
	os.setf(initial);
}



