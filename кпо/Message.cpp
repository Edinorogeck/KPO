#include "Message.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <bitset>



using std::string;

using std::ifstream;
using std::stringstream;

using std::cout;
using std::cerr;
using std::cin;
using std::endl;



Message::Message(string nameExcelFile)
{
    string line = "";
    ifstream workFile(nameExcelFile);
    string nameOfParam, sizeOfParam;

    char delimiter = ';';

    while (getline(workFile, line))
    {
        stringstream stream(line);
        getline(stream, nameOfParam, delimiter);
        getline(stream, sizeOfParam, delimiter);

        parametrsArray.push_back(Parameter(nameOfParam, sizeOfParam));
    }
    workFile.close();
}

string Message::MakeMessage()
{
    std::string message = MakeMessageMKIO_SD();

    return message;
}



void Message::SetAddressOY(string address)
{
    this->addressOY = string(address);
}

string Message::GetAddressOY()
{
    return string(this->addressOY);
}

void Message::PrintMessage()
{
    int a = this->parametrsArray.size();
    for (int i = 0; i < a; i++)
    {
        cout << this->parametrsArray[i].GetParametrName() << "      " << this->parametrsArray[i].GetParametrTypeCode() << "      " << this->parametrsArray[i].GetBinValue() << endl;
    }
}

Message::~Message()
{
}

std::string Message::MakeMessageMKIO_SD()
{
    if (parametrsArray.size() == 0) {
        cerr << "Error: Empty parameter name" << endl;
        return std::string("");
    }

    std::string stringParametrs = "";
    for (int i = 0; i < this->parametrsArray.size(); i++)
    {
        stringParametrs += this->parametrsArray[i].GetBinValue();
    }

    int k;
    if (stringParametrs.length() % 16 == 0)
    {
        k = stringParametrs.length() / 16;
    }
    else
    {
        k = stringParametrs.length() / 16 + 1;
    }
    std::string message = "";
    message += "1001";
    message += this->addressOY;
    message += "1";
    message += "00010";

    std::bitset<sizeof(int8_t) * 8> bitSetK((int8_t)k);

    message += bitSetK.to_string();
    message += "9";

    for (int i = 0; i < k; i++)
    {
        message += "1001";
        message += stringParametrs.substr(0, 16);
        stringParametrs.erase(0, 16);
        message += "9";
    }






    return string(message);
}
