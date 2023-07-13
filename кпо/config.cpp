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
    // ����������� ��� �����
    setlocale(LC_ALL, "ru_RU");
    // ���� � ����������������� �����
    string path = MAIN_PATH + CONFIGURATION_FILE;

    // �������� ������� ����� �� ����
    if (std::filesystem::exists(path)) {
        //std::cout << "File exists!" << std::endl;
    }
    else {
        std::cout << "File does not exist." << std::endl;
    }

    string line = "";
    ifstream configurationFile(path, ios::binary);

    // �������� ����� �� ��������
    if (!configurationFile.is_open()) {
        cout << "File not open." << endl;
    }

    // �������������� � ��������� win1251
    configurationFile.imbue(locale("rus_rus.1251"));
    string path_message = "";



  







    // 
    // ���� ���������� ��������� ����������
    //






    // ����� �� ����� �������� ������ ���������
    while (getline(configurationFile, line))
    {


        MessagePrototype ms;

        //cout << line << endl;

        // �������� ����� ������������ ���������
        path_message = MAIN_PATH + line;
        path_message.erase(path_message.size() - 1);


        // �������� �� ������� ����� ������
        //if (std::filesystem::exists(path_message)) {
        //    cout << "File exists!" << endl;
        //}
        //else {
        //    cout << "File does not exist." << endl;
        //}


        ifstream messageFile;
        // �������� �����
        messageFile.open(path_message);

        // ���������� ������ ����� ������������ ���������
        vector<string> arrayMessageLine;
        string messageLine;
        bool isFirstIteration = true;
        while (getline(messageFile, messageLine))
        {
            arrayMessageLine.push_back(messageLine);
            //cout << messageLine << endl;
        }


        // ���������� ���������
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


        // ���������� ��������� � ������ ��������
        arrayMessagePrototypes.push_back(ms);
        messageFile.close();
    }










    //PrintArrayMessagePrototypes(arrayMessagePrototypes);



    //// �������� ����� �� �������� �� i-��� �������
    //int i = 0;
    //while (i < path_message.length() && i < new_path_message.length()) {
    //    if (path_message[i] != new_path_message[i]) {
    //        cout << "������ ����������� �� ������� " << i << endl;
    //        break;
    //    }
    //    i++;
    //}


    //// �������� ����� �� ������������
    //if (path_message == new_path_message) {
    //    cout << path_message << " = " << new_path_message << endl;       
    //} else {
    //    cout << path_message << " != " << new_path_message << endl;
    //}






    configurationFile.close();
}

// ����� �� ����� ������ ������������ ���������
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


// Eth ��� ����
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
    if (type == "����") {
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




