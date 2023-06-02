#include <iostream>
#include <string>

#include "Myclass.h"


using namespace std;







int main() {
    
    string val1;
    int val2;
    cout << "Enter octal value of N1: ";
    cin >> val1;

    cout << "Enter decimal value of N2: ";
    cin >> val2;




    Numeral_8 N1(val1);
    Numeral_8 N2(val2);
    Numeral_8 N3;





    int value;
    cout << "Enter the value to increase N2: ";
    cin >> value;

    ++N1;
    N2 += value;



    N3 = N1 + N2;


    string binaryNormal = N3.convertToBinary();

    string binaryShortcut = N3.convertToBinaryShortcut();


    cout << "Modified N1: " << N1.getOctalNumber() << endl;
    cout << "Modified N2: " << N2.getOctalNumber() << endl;
    cout << "Sum of modified N1 and N2: " << N3.getOctalNumber() << endl;

    cout << "Binary representation (normal): " << binaryNormal << endl;
    cout << "Binary representation (shortcut): " << binaryShortcut << endl;

    return 0;
}
