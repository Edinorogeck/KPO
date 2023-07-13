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

    // ������� ����� ��
    std::string GetAddressOY();


  
    
    
    
    
    
    
    std::string MakeMessage();


    void PrintMessage();
    


    




    ~Message();

private:
    // ��� ���������
    std::string messageName;
    // ��� ��������� �������� ���������
    std::string typeMessage;
    // ����� ��
    std::vector<std::string> addressOY;
    // ������ ����������
    std::vector <Parameter> parametrsArray;




};















#endif