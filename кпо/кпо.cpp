// кпо.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "config.h"








using std::cout;
using std::cin;
using std::endl;






int main()
{
    
    Configuration();
    string messageName = "Вх.МКИО.15";



    


    MessagePrototype mp;
    mp = GetMessagePrototype(messageName);

    cout << mp.type << endl;

}
