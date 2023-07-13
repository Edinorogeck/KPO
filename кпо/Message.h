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

    // ���������� ����� �� 
    void SetAddressOY(std::string);
    // ������� ����� ��
    std::string GetAddressOY();

    void PrintMessage();
    ~Message();


    // ������ ����������
    std::vector <Parameter> parametrsArray;






private:
    // ��� ���������
    std::string messageName;
    // ��� ��������� �������� ���������
    std::string typeMessage;
    // ����� ��
    std::string addressOY;


    // ������� �������� ���� ��������� ����� ������
    std::string MakeMessageMKIO_SD();


};















#endif