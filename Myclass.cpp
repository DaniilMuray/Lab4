//
// Created by Legion on 5/26/2023.
//

#include "Myclass.h"



    // Constructors
    Numeral_8::Numeral_8() : octalNumber("0") {}
    Numeral_8::Numeral_8(const string& octal) : octalNumber(octal) {}
    Numeral_8::Numeral_8(int decimal) {
        octalNumber = convertDecimalToOctal(decimal);
    }

    // Getter
    string Numeral_8::getOctalNumber() const {
        return octalNumber;
    }

    // Conversion methods
    int Numeral_8::convertOctalToDecimal(const std::string& octal) {
        int decimal = 0;
        int power = octal.length() - 1;
        for (char octalDigit : octal) {
            int digit = octalDigit - '0';
            decimal += digit * pow(8, power);
            power--;
        }
        return decimal;
    }


    string Numeral_8::convertDecimalToOctal(int decimal) const {
        std::string result;
        if (decimal == 0) {
            result = "0";
        } else {
            while (decimal > 0) {
                int remainder = decimal % 8;
                result = std::to_string(remainder) + result;
                decimal /= 8;
            }
        }
        return result;
    }

    string Numeral_8::convertToBinary() const {
        string binary;
        for (char octalDigit : octalNumber) {
            int digit = octalDigit - '0';
            string binaryDigit;
            while (digit > 0) {
                binaryDigit = std::to_string(digit % 2) + binaryDigit;
                digit /= 2;
            }
            binary += binaryDigit;
        }
        return binary;
    }

    string Numeral_8::convertToBinaryShortcut() const {
        string binary;
        for (char octalDigit : octalNumber) {
            int digit = octalDigit - '0';
            binary += to_string(digit / 4);
            binary += to_string((digit % 4) / 2);
            binary += to_string((digit % 4) % 2);
        }
        return binary;
    }

    // Operator overloading
        Numeral_8 &Numeral_8::operator++() {
        int decimal = convertOctalToDecimal(octalNumber);
        decimal++;
        octalNumber = convertDecimalToOctal(decimal);
        return *this;
    }



        Numeral_8 &Numeral_8::operator+=(int value) {
        int decimal = convertOctalToDecimal(octalNumber);
        decimal += value;
        octalNumber = convertDecimalToOctal(decimal);
        return *this;
    }

        Numeral_8 Numeral_8::operator+(const Numeral_8& other) const {
        int decimal1 = convertOctalToDecimal(octalNumber);
        int decimal2 = convertOctalToDecimal(other.octalNumber);
        int sum = decimal1 + decimal2;
        return Numeral_8(sum);
    }
