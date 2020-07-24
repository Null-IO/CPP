#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

class PC {
private:
	string CPU;
	string GPU;
	int MemSize;
	PC(){};
	friend const string getClassCPU(const PC & obj);
protected:
	PC(const string & setCPU, const string & setGPU, int setMemSize) : CPU(setCPU), GPU(setGPU), MemSize(setMemSize) {}
public:
	virtual ~PC(){};
	virtual void Display() const {printf("%s %s %d\n", CPU.c_str(), GPU.c_str(), MemSize);}
	const string & getCPU () const {return CPU;}
	const string & getGPU () const {return GPU;}
	int getMemSize () const {return MemSize;}
};

class PnP {
private:
	string PnPdevice;
	PnP(){};
protected:
	PnP(string PnPsetter) : PnPdevice(PnPsetter) {}
public:
	const string getPnP() const {return PnPdevice;}
};

class Z1 : public PC {
private:
	string Case;
public:
	Z1() : PC("i5-2400", "GTX 1060", 12228), Case("Zalman T4 ") {};
	void Display() const { printf("Overloaded Function\n"); }
	const string & getCase () const {return Case;}

};

class Z2 : public PC, public PnP {
private:
	string Cooler;
public:
	Z2() : PC("Xeon E5450", "GTX 1050", 8192), PnP("Printer") ,Cooler("Zalman CNPS 5x\n") {};
	const string & getCooler() const { return Cooler; }
};

const string getClassCPU(const PC & obj){
	return obj.CPU + "Z";
}

int main(int argc, char ** argv) {
	//Can't create actual object from baseclass as it gives an error cause constructor is in protected!
	
	Z1 p1;
	Z2 p2;
	
	p1.Display();
	printf("%s\n", p1.getCase().c_str());
	p2.Display();
	printf("%s", p2.getCooler().c_str());
	printf("%s --> multi inheritance\n", p2.getPnP().c_str());
	
	printf("%s - non-class friendly function!\n", getClassCPU(p1).c_str());
	
	PC *p[] = {&p1, &p2};
	
	for(PC *i : p)
		i->Display(); //keyword "virtual" tells compiler that function is overloaded P.s u need destructor in order to use virtual
	
}


