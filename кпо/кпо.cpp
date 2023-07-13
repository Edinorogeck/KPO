﻿// кпо.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <filesystem>
#include <list>
#include <vector>
#include <locale>

using std::ios;

using std::ifstream;

using std::string;

using std::cout;
using std::cin;
using std::endl;


using std::locale;

using std::list;
using std::vector;

string MAIN_PATH = "Configuration_folder/";
string CONFIGURATION_FILE = "Configuration_file.txt";

struct ParametrData
{
    string parametrName;
    string parametrSize;
};

struct MessagePrototype
{
    string name;
    string type;
    vector<string> address;
    vector<ParametrData> messageData;
};



string GetMessageName(string s) {
    string line;
    std::istringstream ss(s);
    while (getline(ss, line, ';'))
    {
        return line;
    }
}



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
        while (getline(ss, line, ';')){
            address.push_back(line);
            return address;
        }
    }
    if (type == "Eth")
    {
        while (getline(ss, line, ';')){
            address.push_back(line);
        }
        return address;
    }   
}


void PrintArrayMessagePrototypes(vector<MessagePrototype> ms) {
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















int main()
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
        return 1;
    }
    
    // Преобразование в кодировку win1251
    configurationFile.imbue(locale("rus_rus.1251"));
    string path_message = "";



    vector<MessagePrototype> arrayMessagePrototypes;


    




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

    }








    

    PrintArrayMessagePrototypes(arrayMessagePrototypes);



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
