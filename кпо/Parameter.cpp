#include "Parameter.h"
#include "config.h"

#include <iostream>
#include <cstdint>
#include <bitset>


using std::string;

using std::cerr;
using std::cout;
using std::cin;
using std::endl;

using std::bitset;



long binaryToDecimal(string binary) {
    int decimal = 0;
    int sign = 1;
    if (binary[0] == '1') {
        sign = -1;
        // инвертируем биты
        for (int i = 0; i < binary.length(); i++) {
            if (binary[i] == '0') {
                binary[i] = '1';
            }
            else {
                binary[i] = '0';
            }
        }
        // добавляем единицу
        for (int i = binary.length() - 1; i >= 0; i--) {
            if (binary[i] == '0') {
                binary[i] = '1';
                break;
            }
            else {
                binary[i] = '0';
            }
        }
    }
    // преобразуем в десятичное число
    for (int i = 0; i < binary.length(); i++) {
        int bit = binary[binary.length() - 1 - i] - '0';
        decimal += bit * pow(2, i);
    }
    return sign * decimal;
}

string toBinaryString(long n, int size) {
    bitset<32> bits(n);
    std::string binaryString = bits.to_string().substr(32 - size);
    return binaryString;
}








Parameter::Parameter()
{
}

Parameter::Parameter(string str, int size)
{
    this->parametrName = str;
    this->type = str.substr(str.rfind('_') + 1);
    this->size = size;
    this->value = "";
}

void Parameter::SetValue(std::string str)
{
    this->value = str;

    //long number = binaryToDecimal(str) / CMR;
    //this->value = toBinaryString(number, this->size);
}

void Parameter::SetValue(unsigned char* byteArray)
{
    string str;

    for (int i = 0; i < this->size; i++) {
        if (byteArray[i])
        {
            str = '1' + str;
        }
        else
        {
            str = '0' + str;
        }
    }
    this->value = str;
}

std::string Parameter::GetValue()
{
    return this->value;
}

int Parameter::GetSize()
{
    return this->size;
}

std::string Parameter::MakeString()
{
    string str = "";
    int pos = 0;
    for (int i = 0; i < this->size / 8; i++)
    {
        //cout << this->value.substr(pos, 8) << endl;
        str = str + std::string(1, static_cast<char>(std::bitset<8>(this->value.substr(pos, 8)).to_ulong()));
        pos += 8;
    }
    return str;
}




Parameter::~Parameter()
{
}


