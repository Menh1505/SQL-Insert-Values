#pragma once
#include <list>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class InsertSqlValue
{
public:
    list<string> listData;
    int n_column;
    short *column;

    InsertSqlValue();
    void GetDataToList(fstream &fi);
    void GetNumberOfColumn();
    void DefineColumn();
    list<string> SplitString(string str, char splitChar);
    void FormatString(string &str);
    void insertZero(string &str);
    void PrintData(fstream &fo);
    ~InsertSqlValue();
};