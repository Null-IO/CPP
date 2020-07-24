#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

class Encryption {
private:
	const static int key = 91;
	const static int maxSize = 1024;
	const char *fileName = "Encryption2.txt";
	char buff[maxSize];
	string Message;
public:
	explicit Encryption(string setMessage) : Message(setMessage) {};
	void Encrypt_file();
	string En_De_cryption();
	~Encryption() { Message = ""; };
};

string Encryption::En_De_cryption() {
	for(int i = 0; i < Message.size(); i++)
		Message[i] ^= key;
	
	return Message;
}

void Encryption::Encrypt_file() {
	FILE *fw = fopen(fileName, "w");
	fputs(Message.c_str(), fw);
	int k = 0;
	
	fclose(fw);
	
	FILE *fr = fopen(fileName, "r");
	FILE *fw2 = fopen("Decrypted2.txt", "w");
	
	if(fgets(buff, maxSize, fr) != nullptr)
		fgets(buff, maxSize, fr);
	
	for(int i = 0; i < Message.size(); i++)
		buff[i] ^= key;
	
	fputs(buff, fw2);
	
	fclose(fw2);
	fclose(fr);
	puts("Encryption Complete");
}

int main(int argc, char ** argv) {
	char buff[128]; 
	cin.getline(buff, sizeof(buff));
	string str = buff;
	Encryption Z(str);
	Z.En_De_cryption();
	Z.Encrypt_file();
}


