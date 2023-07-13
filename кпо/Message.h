#pragma once


#ifndef MESSAGE_H
#define MESSAGE_H





#include <string>
#include <vector>
#include "Parameter.h"



class Message
{
public:
    Message(std::string);

    std::string MakeMessage();

    // Установить адрес ОУ 
    void SetAddressOY(std::string);
    // Вернуть адрес ОУ
    std::string GetAddressOY();

    void PrintMessage();
    ~Message();


    // Массив параметров
    std::vector <Parameter> parametrsArray;






private:
    // Имя сообщения
    std::string messageName;
    // Тип сообщения согласно стандарту
    std::string typeMessage;
    // Адрес ОУ
    std::string addressOY;


    // Функция создания мкио сообщения слова данных
    std::string MakeMessageMKIO_SD();


};















#endif