#include "Message.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <bitset>
#include <tuple>
#include <vector>

typedef unsigned char BYTE;

using std::string;

using std::ifstream;
using std::stringstream;

using std::cout;
using std::cerr;
using std::cin;
using std::endl;

using std::tuple;



// функция преобразования вектора байт в бинарную строку
string byteToBinaryString(vector<BYTE>& byteArray, int size) {
    //std::ostringstream oss;
    string str = "";
    for (int i = 0; i < size; ++i) { // для каждого байта в массиве
        str = str + std::bitset<8>(static_cast<unsigned int>(byteArray[i])).to_string();
    }
    return str; 
}











Message::Message()
{
}

Message::Message(MessagePrototype msProto)
{
    this->messageName = msProto.name;
    this->typeMessage = msProto.type;
    this->addressOY = msProto.address;

    for (int i = 0; i < msProto.messageData.size(); i++){
        int size = std::stoi(msProto.messageData[i].parametrSize);
        Parameter p = Parameter(msProto.messageData[i].parametrName, size);
        this->parametrsArray.push_back(p);        
    }
}

void Message::SetValues(std::string valueStr)
{
    std::string binary_str = "";

    for (char c : valueStr) {
        std::bitset<8> binary(c);
        binary_str += binary.to_string();
    }


    //string str = valueStr;
    for (int i = 0; i < this->parametrsArray.size(); i++)
    {
        string newStr = binary_str.substr(0, this->parametrsArray[i].GetSize());
        this->parametrsArray[i].SetValue(newStr);
        binary_str.erase(0, this->parametrsArray[i].GetSize());
    }    
}

void Message::SetValues(vector<BYTE>& data)
{
    //string strParametrValue = "";

    int size = 0;

    for (int i = 0; i < parametrsArray.size(); i++)
    {
        vector<BYTE> subVect;
        for (int j = 0; j < (parametrsArray[i].GetSize() / 8); j++)
        {
            subVect.push_back(data[size + j]);
        }
        size += parametrsArray[i].GetSize() / 8;
        //cout << byteToBinaryString(subVect, parametrsArray[i].GetSize() / 8) << endl;

        parametrsArray[i].SetValue(byteToBinaryString(subVect, parametrsArray[i].GetSize() / 8));
        subVect.clear();
    }
}

string Message::MakeOutputString()
{
    string str = "";
    for (int i = 0; i < parametrsArray.size(); i++)
    {
        str = str + parametrsArray[i].MakeString();
    }

    return str;
}





std::tuple<vector<BYTE>, vector<string>> Message::MakeOutputTuple()
{
    vector<BYTE> array;
    vector<string> address;


    int pos = 0;
    for (int i = 0; i < parametrsArray.size(); i++)
    {
        for (int j = 0; j < parametrsArray[i].GetSize() / 8; j++)
        {
            string str = parametrsArray[i].GetValue().substr(pos, 8);
            pos = pos + 8;
            std::bitset<8> bits(str);
            array.push_back(static_cast<unsigned char>(bits.to_ulong()));
        }
        pos = 0;

    }

    address = this->addressOY;



    return std::make_tuple(array, address);
}






std::string Message::GetAddressOY()
{
    if (this->typeMessage == "МКИО")
    {
        return this->addressOY[0];
    }
    else
    {
        return this->addressOY[0] + this->addressOY[1];
    }
}

// моя сервисная функция
void Message::PrintMessage()
{
    for (int i = 0; i < this->parametrsArray.size(); i++)
    {
        cout << this->parametrsArray[i].GetValue() << endl;
    }

    for (int i = 0; i < this->parametrsArray.size(); i++)
        {
            cout << this->parametrsArray[i].MakeString() << endl;
        }

}

Message::~Message()
{
}






