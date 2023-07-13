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


    // ������� ����� ��
    std::string GetAddressOY();

    // ��� ��������� �������
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