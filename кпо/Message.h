#pragma once


#ifndef MESSAGE_H
#define MESSAGE_H





#include <string>
#include <vector>
#include "Parameter.h"
#include "config.h"



class Message
{
public:

    Message();
    Message(MessagePrototype);



    void SetValues(std::string);

    // Вернуть адрес ОУ
    std::string GetAddressOY();


  
    
    
    
    
    
    
    std::string MakeMessage();


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