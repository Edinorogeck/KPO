#include "Message.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <bitset>
#include <tuple>


using std::string;

using std::ifstream;
using std::stringstream;

using std::cout;
using std::cerr;
using std::cin;
using std::endl;

using std::tuple;


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

std::string Message::GetAddressOY()
{
    if (this->typeMessage == "ÌÊÈÎ")
    {
        return this->addressOY[0];
    }
    else
    {
        return this->addressOY[0] + this->addressOY[1];
    }
}




//
//std::tuple<Address, string> Message::MakeMessage()
//{
//    std::tuple<Address, string> a;
//    string str = "";
//    if (this->typeMessage == "Eth")
//    {
//        for (int i = 0; i < this->parametrsArray.size(); i++)
//        {
//            str += this->parametrsArray[i].GetBinValue();
//        }
//        Address address;
//        address.address1 = this->addressOY[0]; 
//        address.address2 = this->addressOY[1];
//        a = std::make_tuple(address, str);
//    }
//    if (this->typeMessage == "ÌÊÈÎ")
//    {
//        for (int i = 0; i < this->parametrsArray.size(); i++)
//        {
//            str += this->parametrsArray[i].GetBinValue();
//        }
//        Address address;
//        address.address1 = this->addressOY[0];
//        a = std::make_tuple(address, str);
//    }
//    return std::tuple<Address, string>();
//}





void Message::PrintMessage()
{
    for (int i = 0; i < this->parametrsArray.size(); i++)
    {
        cout << this->parametrsArray[i].GetValue() << endl;
    }
}

Message::~Message()
{
}









