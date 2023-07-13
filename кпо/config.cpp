#include "config.h"



#include <iostream>
#include <fstream>
#include <sstream>

#include <filesystem>

#include <locale>

using std::ios;

using std::ifstream;


using std::cout;
using std::cin;
using std::endl;


using std::locale;

using std::list;


string MAIN_PATH = "Configuration_folder/";

string CONFIGURATION_FILE = "Configuration_file.txt";


vector<MessagePrototype> arrayMessagePrototypes;


void Configuration()
{
    // Подключение рус языка
    setlocale(LC_ALL, "ru_RU");
    // Путь к конфигурационному файлу
    string path = MAIN_PATH + CONFIGURATION_FILE;

    // Проверка наличия файла по пути
    if (std::filesystem::exists(path)) {
        //std::cout << "File exists!" << std::endl;
    }
    else {
        std::cout << "File does not exist." << std::endl;
    }

    string line = "";
    ifstream configurationFile(path, ios::binary);

    // Проверка файла на открытие
    if (!configurationFile.is_open()) {
        cout << "File not open." << endl;
    }

    // Преобразование в кодировку win1251
    configurationFile.imbue(locale("rus_rus.1251"));
    string path_message = "";



  







    // 
    // Блок объявления локальных переменных
    //






    // Вывод на экран названий файлов сообщений
    while (getline(configurationFile, line))
    {


        MessagePrototype ms;

        //cout << line << endl;

        // Открытие файла конфигурации сообщения
        path_message = MAIN_PATH + line;
        path_message.erase(path_message.size() - 1);


        // Проверка на наличие файла попути
        //if (std::filesystem::exists(path_message)) {
        //    cout << "File exists!" << endl;
        //}
        //else {
        //    cout << "File does not exist." << endl;
        //}


        ifstream messageFile;
        // Открытие файла
        messageFile.open(path_message);

        // Построчное чтение файла конфигурации сообщения
        vector<string> arrayMessageLine;
        string messageLine;
        bool isFirstIteration = true;
        while (getline(messageFile, messageLine))
        {
            arrayMessageLine.push_back(messageLine);
            //cout << messageLine << endl;
        }


        // Заполнение структуры
        ms.name = GetMessageName(arrayMessageLine[1]);
        ms.type = GetMessageType(ms.name);
        ms.address = GetMessageAddress(arrayMessageLine[2], ms.type);

        for (int i = 3; i < arrayMessageLine.size(); i++)
        {
            vector<string> ss;
            string str;
            std::istringstream s(arrayMessageLine[i]);
            while (getline(s, str, ';')) {
                ss.push_back(str);
            }
            ParametrData pd;
            pd.parametrName = ss[0];
            pd.parametrSize = ss[1];
            ms.messageData.push_back(pd);
        }


        // Добавление структуры в массив структур
        arrayMessagePrototypes.push_back(ms);
        messageFile.close();
    }










    //PrintArrayMessagePrototypes(arrayMessagePrototypes);



    //// Проверка строк на различие на i-том символе
    //int i = 0;
    //while (i < path_message.length() && i < new_path_message.length()) {
    //    if (path_message[i] != new_path_message[i]) {
    //        cout << "Строки различаются на символе " << i << endl;
    //        break;
    //    }
    //    i++;
    //}


    //// Проверка строк на идентичность
    //if (path_message == new_path_message) {
    //    cout << path_message << " = " << new_path_message << endl;       
    //} else {
    //    cout << path_message << " != " << new_path_message << endl;
    //}






    configurationFile.close();
}

// Вывод на экран ветора конфигураций сообщений
void PrintArrayMessagePrototypes() {
    vector<MessagePrototype> ms = arrayMessagePrototypes;


    for (int i = 0; i < ms.size(); i++)
    {
        cout << ms[i].name << "      " << ms[i].type << endl;
        //cout << ms[i].address.size() << "           " << ms[i].messageData.size() << endl;

        for (int j = 0; j < ms[i].address.size(); j++) {
            cout << ms[i].address[j] << endl;
        }
        for (int j = 0; j < ms[i].messageData.size(); j++) {
            cout << ms[i].messageData[j].parametrName << "      " << ms[i].messageData[j].parametrSize << endl;
        }

    }
}

bool if_find(string name)
{
    for (int i = 0; i < arrayMessagePrototypes.size(); i++) {
        if (arrayMessagePrototypes[i].name == name) {
            return true;
        }
    }
    return false;
}

MessagePrototype GetMessagePrototype(string name)
{
    for (int i = 0; i < arrayMessagePrototypes.size(); i++)
    {
        if (arrayMessagePrototypes[i].name == name) {
            return arrayMessagePrototypes[i];
        }
    }
}




string GetMessageName(string s) {
    string line;
    std::istringstream ss(s);
    while (getline(ss, line, ';'))
    {
        return line;
    }
}


// Eth или МКИО
string GetMessageType(string s) {
    string line;
    std::istringstream ss(s);
    vector<string> ssVector;
    while (getline(ss, line, '.'))
    {
        ssVector.push_back(line);
    }
    return ssVector[1];
}

vector<string> GetMessageAddress(string s, string type) {
    vector<string> address;
    string line;
    std::istringstream ss(s);
    if (type == "МКИО") {
        while (getline(ss, line, ';')) {
            address.push_back(line);
            return address;
        }
    }
    if (type == "Eth")
    {
        while (getline(ss, line, ';')) {
            address.push_back(line);
        }
        return address;
    }
}




