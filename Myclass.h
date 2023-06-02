//
// Created by Legion on 5/26/2023.
//

#ifndef LAB4_1_MYCLASS_H
#define LAB4_1_MYCLASS_H


#include <iostream>
#include <string>
#include <cmath>


using namespace std;


class Numeral_8{
private:
    string octalNumber;
public:
    Numeral_8();
    Numeral_8(const string& octal);
    Numeral_8(int decimal);

    string getOctalNumber() const;
    static int convertOctalToDecimal(const std::string& octal);
    string convertDecimalToOctal(int decimal) const;
    string convertToBinary() const;
    string convertToBinaryShortcut() const;

    Numeral_8& operator++();
    Numeral_8& operator+=(int value);
    Numeral_8 operator+(const Numeral_8& other) const; // Declaration

};



#endif //LAB4_1_MYCLASS_H
