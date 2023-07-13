// кпо.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "config.h"
#include "Message.h"
#include "Parameter.h"
#include <bitset>







using std::cout;
using std::cin;
using std::endl;







int main()
{
    
    string tip_s = "11";
    string Rez = "1";
    string rezerv = "01010";
    string nom_cikl = "00110011";
    string CV_TekVrem_U32 = "00000000111111110000000011111111";
    string CRC16 = "0000111100001111";

    string msString = tip_s + Rez + rezerv + nom_cikl +
        CV_TekVrem_U32 + CRC16;

    
    cout << msString << endl;

    Configuration();

    string messageName = "Вх.МКИО.15";
    
    MessagePrototype mp;
    mp = GetMessagePrototype(messageName);



    Message ms = Message(mp);


    

    cout << mp.type << endl;
    cout << ms.GetAddressOY() << endl;

    ms.SetValues(msString);
    ms.PrintMessage();



    cout << "---------------" << endl;

    std::string binary_str = "";

    for (char c : msString) {
        std::bitset<8> binary(c);
        binary_str += binary.to_string();
    }
    cout << binary_str << endl;

}
