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
    //Конструктор по названию и размеру
    Parameter(std::string, int);

    //Установить значение
    void SetValue(std::string);
    
    void SetValue(unsigned char* byteArray);

    std::string GetValue();
    int GetSize();






    std::string GetParametrName();
    std::string GetParametrTypeCode();
    std::string GetBinValue();

    



    ~Parameter();
private:

    //название параметра
    std::string parametrName;

    //код параметра U32, I16, I8 или другие
    std::string type;

    //размер поля
    int size;

    // Значение параметра
    std::string value;



};


#endif