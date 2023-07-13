#pragma once


#ifndef CONFIG_H
#define CONFIG_H



#include <unordered_map>

#include <string>
#include <vector>



using std::unordered_map;
using std::string;

using std::vector;


extern string MAIN_PATH;
extern string CONFIGURATION_FILE;

int CMR = 4;



struct ParametrData
{
    string parametrName;
    string parametrSize;
};




unordered_map <string, MessagePrototype> arrayMessagePrototypes;








void Configuration();

void PrintArrayMessagePrototypes(unordered_map <string, MessagePrototype> array);

MessagePrototype GetMessagePrototype(string name);




string GetMessageName(string s);

string GetMessageType(string s);

vector<string> GetMessageAddress(string s, string type);





























































































#endif // !CONFIG_H
