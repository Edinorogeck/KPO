// кпо.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "config.h"
#include "Message.h"
#include "Parameter.h"
#include "conv_functions.cpp"
#include <bitset>
#include <ostream>



typedef unsigned char BYTE;



using std::cout;
using std::cin;
using std::endl;






int main()
{

    vector<BYTE> data = { 77, 88, 99, 110, 120, 130, 140 };

  
    Configuration();

    string messageName = "Вх.МКИО.766";
    
    MessagePrototype mp;
    mp = GetMessagePrototype(messageName);


    



    Message ms = Message(mp);


    

    cout << mp.type << endl;
    cout << ms.GetAddressOY() << endl;

   
    ms.SetValues(data);

    




}
