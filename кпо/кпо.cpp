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



// Проверка на входящее сообщение или нет
bool Is_Incoming(string name) {
    // находим позицию первой точки в строке
    size_t dot_pos = name.find('.');

    // получаем подстроку до позиции первой точки
    std::string substr = name.substr(0, dot_pos);

    if (substr == "Вх") {
        return true;
    }
    else
    {
        return false;
    }


}





int main()
{

    vector<BYTE> dataByteArray = { 77, 88, 99, 110, 120, 130, 140 };
    string dataString = "MXcnx'?";

  
    Configuration();
    

    string messageName = "Вх.МКИО.766";

    
    MessagePrototype mp;
    mp = GetMessagePrototype(messageName);


    



    Message VhMs = Message(mp);
    Message IshMs = Message(mp);
    
    
    VhMs.SetValues(dataByteArray);
    IshMs.SetValues(dataString);
    
    
    cout << VhMs.MakeOutputString() << endl;
    cout << "-----------------------------" << endl;

    auto [array, Address] = IshMs.MakeOutputTuple();

    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i];
    }

    cout << endl << Address[0];
       

   /* cout << mp.type << endl;
    cout << ms.GetAddressOY() << endl;*/

   
    

    




}
