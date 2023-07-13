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
    //������������ �� ����� ���������
    Parameter(std::string);
    //����������� �� ����� � ���� ����
    Parameter(std::string, std::string);
    //����������� �� ����� � ��������
    Parameter(std::string, void*);
    //����������� �����������
    Parameter(const Parameter& ref_Parametr);


    //-------------------------------------//
    //        �������(������������)        //
    //-------------------------------------//

    //����������� �� �����, ���� � ��������
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

    //�������� ���������
    std::string parametrName;

    //��� ��������� U32, I16, I8 ��� ������
    std::string parametrTypeCode;

    //��������� �� �������� ���������
    void* value = nullptr;

    void MakeValuePointer();

};


#endif