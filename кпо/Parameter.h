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
    //����������� �� ���������
    Parameter();
    //����������� �� �������� � �������
    Parameter(std::string, int);

    //���������� ��������
    void SetValue(std::string);
    
    void SetValue(unsigned char* byteArray);

    std::string GetValue();
    int GetSize();






    std::string GetParametrName();
    std::string GetParametrTypeCode();
    std::string GetBinValue();

    



    ~Parameter();
private:

    //�������� ���������
    std::string parametrName;

    //��� ��������� U32, I16, I8 ��� ������
    std::string type;

    //������ ����
    int size;

    // �������� ���������
    std::string value;



};


#endif