#pragma once


#ifndef MESSAGE_H
#define MESSAGE_H





#include <string>
#include <vector>
#include <tuple>
#include "Parameter.h"
#include "config.h"

struct Address
{
    std::string address1;
    std::string address2;
};







class Message
{
public:
    Message();
    Message(MessagePrototype);

    void SetValues(std::string);

    void SetValues(std::vector<BYTE>&);



    string MakeOutputString();

    std::tuple<vector<BYTE>, vector<string>> MakeOutputTuple();


    // Вернуть адрес ОУ
    std::string GetAddressOY();

    // моя сервисная функция
    void PrintMessage();

    ~Message();




  
private:
      // Имя сообщения
    std::string messageName;
    // Тип сообщения согласно стандарту
    std::string typeMessage;
    // Адрес ОУ
    std::vector<std::string> addressOY;
    // Массив параметров
    std::vector <Parameter> parametrsArray;
};


#endif