#pragma once

#ifndef PARAMETR_H
#define PARAMETR_H

#include <string>
//#include <cstdint>
//#include <iostream>
//#include <bitset>


class Parameter
{
public:
    //конструктор по умолчанию
    Parameter();
    //конструкттор по имени параметра
    Parameter(std::string);
    //конструктор по имени и коду типа
    Parameter(std::string, std::string);
    //конструктор по имени и значению
    Parameter(std::string, void*);
    //конструктор копирования
    Parameter(const Parameter& ref_Parametr);


    //-------------------------------------//
    //        сделать(конструкторы)        //
    //-------------------------------------//

    //конструктор по имени, типу и значению
    Parameter(std::string, std::string, void*);


    std::string GetParametrName();
    std::string GetParametrTypeCode();
    std::string GetBinValue();

    void* GetValue();

    void SetValue(void* item);

    void PrintParametrName();
    void PrintParametrTypeCode();
    void PrintValue();




    ~Parameter();
private:

    //название параметра
    std::string parametrName;

    //код параметра U32, I16, I8 или другие
    std::string parametrTypeCode;

    //указатель на значение параметра
    void* value = nullptr;

    void MakeValuePointer();

};


#endif