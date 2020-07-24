#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    const int Max = 5;
    int Arr[Max];
    cout << "Please enter Scores" << " Max =" << Max << endl;
    
    for(int i = 0; i < Max; ++i) {
        cout << "Scores #" << i + 1 << endl;
        while(!(cin >> Arr[i])) {
            cin.clear();
            while(cin.get() != '\n')
                continue;
            
            cout << "Please enter a number: "; 
        }
    }
    double avg = 0;
    for(int i = 0; i < Max; i++)
        avg += Arr[i];
    
    cout << avg / Max;
}
