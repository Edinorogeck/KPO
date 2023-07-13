#pragma once

#ifndef CONFIG_H
#define CONFIG_H




#include <string>
#include <vector>




using std::string;

using std::vector;


extern string MAIN_PATH;
extern string CONFIGURATION_FILE;

const double CMR = 4;



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










int Configuration();

void PrintArrayMessagePrototypes(vector<MessagePrototype> ms);

bool if_find(string name);

MessagePrototype GetMessagePrototype(string name);




string GetMessageName(string s);

string GetMessageType(string s);

vector<string> GetMessageAddress(string s, string type);





























































































#endif // !CONFIG_H
