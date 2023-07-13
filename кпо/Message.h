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

    // Вернуть адрес ОУ
    std::string GetAddressOY();


  
    
    
    
    
    
    

    //tuple<Address, string> MakeMessage();

    void PrintMessage();
    


    




    ~Message();

private:

    // Тип сообщения согласно стандарту
    std::string typeMessage;
    // Адрес ОУ
    std::vector<std::string> addressOY;
    // Массив параметров
    std::vector <Parameter> parametrsArray;




};















#endif