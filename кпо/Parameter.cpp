#include "Parameter.h"


#include <iostream>
#include <cstdint>
#include <bitset>


using std::string;

using std::cerr;
using std::cout;
using std::cin;
using std::endl;

using std::bitset;



string GetTypeFromName(string name) {

    // переделать нулевую длину на исключение//

    char c = '_';
    if (name.size() == 0) {
        //cout << "null size" << endl;
        return name;
    }
    if (name.rfind(c) != std::string::npos) {
        //cout << name.rfind(c) << endl;
        string substr = name.substr(name.rfind(c) + 1);
        //cout << substr << endl;
        return substr;
    }
    else
        return "16";
}




Parameter::Parameter()
{
}

Parameter::Parameter(std::string name)
{
    char c = '_';
    if (name.size() == 0) {
        cerr << "Error: Empty parameter name" << endl;
    }
    else if (name.rfind(c) != std::string::npos) {
        this->parametrName = name;
        string substr = name.substr(name.rfind(c) + 1);
        this->parametrTypeCode = substr;
        MakeValuePointer();
    }
    else {
        this->parametrName = name;
        this->parametrTypeCode = "16";
        MakeValuePointer();
    }
}

Parameter::Parameter(std::string name, std::string codeType)
{
    char c = '_';
    if (name.size() == 0 || codeType.size() == 0) {
        cerr << "Error: Empty parameter name" << endl;
    }
    else if (name.rfind(c) != std::string::npos) {
        string substr = name.substr(name.rfind(c) + 1);
        if (substr == codeType) {
            this->parametrName = name;
            this->parametrTypeCode = substr;
            MakeValuePointer();
        }
        else {
            cerr << "Error: Type mismatch in name and type" << endl;
        }
    }
    else {
        if (name == "CRC16" && codeType == "16") {
            this->parametrName = name;
            this->parametrTypeCode = "16";
            MakeValuePointer();
        }
        else
        {
            cerr << "Error: Type mismatch in name and type. CRC16." << endl;
        }
    }
}





Parameter::Parameter(std::string name, void* pValue)
{
    if (name.size() != 0 && pValue != nullptr) {
        char c = '_';
        if (name.size() == 0) {
            cerr << "Error: Empty parameter name" << endl;
        }
        else if (name.rfind(c) != std::string::npos) {
            this->parametrName = name;
            string substr = name.substr(name.rfind(c) + 1);
            this->parametrTypeCode = substr;
            MakeValuePointer();
        }
        else {
            this->parametrName = name;
            this->parametrTypeCode = "16";
            MakeValuePointer();
        }
        SetValue(pValue);
    }
    else {
        cerr << "Error: Empty input value" << endl;
    }
}

Parameter::Parameter(const Parameter& ref_Parametr)
{
    this->parametrName = ref_Parametr.parametrName;
    this->parametrTypeCode = ref_Parametr.parametrTypeCode;
    MakeValuePointer();
    SetValue(ref_Parametr.value);
}


//-----------------------------------------//
//    сверху +- сделано, надо проверить    //
//-----------------------------------------//



string Parameter::GetParametrName()
{
    return string(this->parametrName);
}

string Parameter::GetParametrTypeCode()
{
    return string(this->parametrTypeCode);
}

string Parameter::GetBinValue()
{
    if (this->parametrTypeCode.size() == 0) {
        return 0;
    }
    else {
        if (this->parametrTypeCode == "U8") {
            if (this->value == nullptr) {
                cerr << "Error: Memory allocation error. nullptr" << endl;
                return 0;
            }
            else {
                bitset<sizeof(uint8_t) * 8> bitSetElement(*(uint8_t*)this->value);
                return bitSetElement.to_string();
            }
        }

        if (this->parametrTypeCode == "I8") {
            //
            //this->value = new int8_t;
            //

            if (this->value == nullptr) {
                cerr << "Error: Memory allocation error. nullptr" << endl;
                return 0;
            }
            else {
                bitset<sizeof(int8_t) * 8> bitSetElement(*(int8_t*)this->value);
                return bitSetElement.to_string();
            }
        }

        if (this->parametrTypeCode == "U16") {
            if (this->value == nullptr) {
                cerr << "Error: Memory allocation error. nullptr" << endl;
                return 0;
            }
            else {
                bitset<sizeof(uint16_t) * 8> bitSetElement(*(uint16_t*)this->value);
                return bitSetElement.to_string();
            }
        }

        if (this->parametrTypeCode == "I16") {
            if (this->value == nullptr) {
                cerr << "Error: Memory allocation error. nullptr" << endl;
                return 0;
            }
            else {
                bitset<sizeof(int16_t) * 8> bitSetElement(*(int16_t*)this->value);
                return bitSetElement.to_string();
            }
        }

        if (this->parametrTypeCode == "U32") {
            if (this->value == nullptr) {
                cerr << "Error: Memory allocation error. nullptr" << endl;
                return 0;
            }
            else {
                bitset<sizeof(uint32_t) * 8> bitSetElement(*(uint32_t*)this->value);
                return bitSetElement.to_string();
            }
        }

        if (this->parametrTypeCode == "I32") {
            if (this->value == nullptr) {
                cerr << "Error: Memory allocation error. nullptr" << endl;
                return 0;
            }
            else {
                bitset<sizeof(int32_t) * 8> bitSetElement(*(int32_t*)this->value);
                return bitSetElement.to_string();
            }
        }

        if (this->parametrTypeCode == "16") {
            if (this->value == nullptr) {
                cerr << "Error: Memory allocation error. nullptr" << endl;
                return 0;
            }
            else {
                bitset<sizeof(unsigned short) * 8> bitSetElement(*(unsigned short*)this->value);
                return bitSetElement.to_string();
            }

            //this->value = new unsigned short;
        }
    }
}

void* Parameter::GetValue()
{
    if (this->value != nullptr) {
        return this->value;
    }
    else {
        cerr << "Error: Empty value of parameter 'value'" << endl;
        return nullptr;
    }
}





void Parameter::SetValue(void* item)
{
    //не проверяется входное данное, просто доверяем что оно соответствует параметру


    /* ---------------------------------------- */

    if (this->parametrTypeCode == "U8") {
        uint8_t pValue = *(uint8_t*)item;
        uint8_t* ptr = new uint8_t;
        if (ptr != nullptr) {
            *ptr = pValue;
            this->value = ptr;
        }
        else {
            cerr << "Error: Memory allocation error for ptr. nullptr" << endl;
            delete ptr;
        }
    }

    if (this->parametrTypeCode == "I8") {
        int8_t pValue = *(int8_t*)item;
        int8_t* ptr = new int8_t;
        if (ptr != nullptr) {
            *ptr = pValue;
            this->value = ptr;
        }
        else {
            cerr << "Error: Memory allocation error for ptr. nullptr" << endl;
            delete ptr;
        }

        //this->value = (int8_t*)item;
    }

    /* ---------------------------------------- */

    if (this->parametrTypeCode == "U16") {
        uint16_t pValue = *(uint16_t*)item;
        uint16_t* ptr = new uint16_t;
        if (ptr != nullptr) {
            *ptr = pValue;
            this->value = ptr;
        }
        else {
            cerr << "Error: Memory allocation error for ptr. nullptr" << endl;
            delete ptr;
        }

        //this->value = (uint16_t*)item;
    }
    if (this->parametrTypeCode == "I16") {
        int16_t pValue = *(int16_t*)item;
        int16_t* ptr = new int16_t;
        if (ptr != nullptr) {
            *ptr = pValue;
            this->value = ptr;
        }
        else {
            cerr << "Error: Memory allocation error for ptr. nullptr" << endl;
            delete ptr;
        }

        //this->value = (int16_t*)item;
    }
    if (this->parametrTypeCode == "U32") {
        uint32_t pValue = *(uint32_t*)item;
        uint32_t* ptr = new uint32_t;
        if (ptr != nullptr) {
            *ptr = pValue;
            this->value = ptr;
        }
        else {
            cerr << "Error: Memory allocation error for ptr. nullptr" << endl;
            delete ptr;
        }

        //this->value = (uint32_t*)item;
    }
    if (this->parametrTypeCode == "I32") {
        int32_t pValue = *(int32_t*)item;
        int32_t* ptr = new int32_t;
        if (ptr != nullptr) {
            *ptr = pValue;
            this->value = ptr;
        }
        else {
            cerr << "Error: Memory allocation error for ptr. nullptr" << endl;
            delete ptr;
        }

        //this->value = (int32_t*)item;
    }
    if (this->parametrTypeCode == "16") {
        unsigned short pValue = *(unsigned short*)item;
        unsigned short* ptr = new unsigned short;
        if (ptr != nullptr) {
            *ptr = pValue;
            this->value = ptr;
        }
        else {
            cerr << "Error: Memory allocation error for ptr. nullptr" << endl;
            delete ptr;
        }

        //this->value = (unsigned short*)item;
    }
}




void Parameter::PrintParametrName() {
    if (this->parametrTypeCode.size() != 0) {
        cout << "Type code : " << this->parametrName << endl;
    }
    else
    {
        cerr << "Error: The 'parametrName' is not known. Possibly an empty instance." << endl;
    }
}

void Parameter::PrintParametrTypeCode() {
    if (this->parametrTypeCode.size() != 0) {
        cout << "Type code : " << this->parametrTypeCode << endl;
    }
    else
    {
        cerr << "Error: The 'parametrTypeCode' is not known. Possibly an empty instance." << endl;
    }
}

void Parameter::PrintValue()
{

    /* ---------------------------------------- */


    /*

    ПРОБЛЕМА C int8_t и uint8_t, ПОЭТОМУ int16_t

    */

    if (this->parametrTypeCode == "U8") {
        //cout << "Value: " << *(uint8_t*)value << endl;
        cout << bitset<sizeof(uint8_t) * 8>(*(uint8_t*)this->value) << "     Parametr::PrintValue" << endl;
    }
    if (this->parametrTypeCode == "I8") {
        cout << "Value: " << *(int8_t*)this->value << endl;
    }

    /* ---------------------------------------- */

    if (this->parametrTypeCode == "U16") {
        cout << "Value: " << *(uint16_t*)this->value << endl;
    }
    if (this->parametrTypeCode == "I16") {
        //cout << sizeof(value) << endl;
        //cout << *(int16_t*)value << "    PrintValue" << endl;
        cout << "Value: " << *(int16_t*)this->value << endl;
    }
    if (this->parametrTypeCode == "U32") {
        //cout << sizeof(value) << endl;
        cout << "Value: " << *(uint32_t*)this->value << endl;
    }
    if (this->parametrTypeCode == "I32") {
        //cout << sizeof(value) << endl;
        cout << "Value: " << *(int32_t*)this->value << endl;
    }
    if (this->parametrTypeCode == "16") {
        //cout << sizeof(*(unsigned short*)value) << endl;
        cout << "Value: " << *(unsigned short*)this->value << endl;
    }
}




Parameter::~Parameter()
{
    //cout << "Destructor of: " << this->parametrName << "     " << this->parametrTypeCode << endl;
    delete value;
}


void Parameter::MakeValuePointer()
{
    if (this->parametrTypeCode == "U8") {
        uint8_t* ptrNew;
        ptrNew = new uint8_t;
        if (ptrNew == nullptr) {
            cerr << "Error: Memory allocation error. nullptr" << endl;
        }
        else {
            this->value = ptrNew;
        }
    }

    if (this->parametrTypeCode == "I8") {
        //
        //this->value = new int8_t;
        //

        int8_t* ptrNew;
        ptrNew = new int8_t;
        if (ptrNew == nullptr) {
            cerr << "Error: Memory allocation error. nullptr" << endl;
        }
        else {
            this->value = ptrNew;
        }
    }

    if (this->parametrTypeCode == "U16") {
        uint16_t* ptrNew;
        ptrNew = new uint16_t;
        if (ptrNew == nullptr) {
            cerr << "Error: Memory allocation error. nullptr" << endl;
        }
        else {
            this->value = ptrNew;
        }
    }

    if (this->parametrTypeCode == "I16") {
        int16_t* ptrNew;
        ptrNew = new int16_t;
        if (ptrNew == nullptr) {
            cerr << "Error: Memory allocation error. nullptr" << endl;
        }
        else {
            this->value = ptrNew;
        }
    }

    if (this->parametrTypeCode == "U32") {
        uint32_t* ptrNew;
        ptrNew = new uint32_t;
        if (ptrNew == nullptr) {
            cerr << "Error: Memory allocation error. nullptr" << endl;
        }
        else {
            this->value = ptrNew;
        }
    }

    if (this->parametrTypeCode == "I32") {
        /*this->value = new int32_t;
        if (this->value == nullptr) {
            cerr << "Error: Memory allocation error. nullptr" << endl;
            delete this->value;
        }*/


        int32_t* ptrNew;
        ptrNew = new int32_t;
        if (ptrNew == nullptr) {
            cerr << "Error: Memory allocation error. nullptr" << endl;
        }
        else {
            this->value = ptrNew;
        }
    }

    if (this->parametrTypeCode == "16") {
        unsigned short* ptrNew;
        ptrNew = new unsigned short;
        if (ptrNew == nullptr) {
            cerr << "Error: Memory allocation error. nullptr" << endl;
        }
        else {
            this->value = ptrNew;
        }


        //this->value = new unsigned short;
    }
}

