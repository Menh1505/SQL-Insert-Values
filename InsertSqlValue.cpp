#pragma once
#include "InsertSqlValue.h"

InsertSqlValue::InsertSqlValue()
{
    n_column = 0;
}

void InsertSqlValue::GetDataToList(fstream &fi)
{
    string line;
    while (getline(fi, line))
    {
        this->listData.push_back(line);
    }
}

void InsertSqlValue::GetNumberOfColumn()
{
    cout << "\nEnter number of column: ";
    cin >> n_column;
}

void InsertSqlValue::DefineColumn()
{
    if (n_column)
    {
        cout << endl;
        column = new short[n_column];
        for (int i = 0; i < n_column; ++i)
        {
            short columnType;
            do
            {
                cout << "Enter type of column " << i + 1 << " (0: data | 1: string | 2: key): ";
                cin >> columnType;
                if (columnType < 0 || columnType > 2)
                    cout << "\n--Invalid value--" << endl;
            } while (columnType < 0 || columnType > 2);
            column[i] = columnType;
        }
    }
}

list<string> InsertSqlValue::SplitString(string str, char splitChar)
{
    list<string> res;
    int startIndex = 0, endIndex = 0;
    for (int i = 0; i <= str.size(); i++)
    {
        if (str[i] == splitChar || i == str.size())
        {
            endIndex = i;
            string temp;
            temp.append(str, startIndex, endIndex - startIndex);
            res.push_back(temp);
            startIndex = endIndex + 1;
        }
    }
    return res;
}
void InsertSqlValue::FormatString(string &str)
{
    while (str[0] == ' ')
    {
        str.erase(0, 1);
    }
    while (str[str.length() - 1] == ' ')
    {
        str.pop_back();
    }
}

void InsertSqlValue::insertZero(string &str)
{
    while (str.length() < 3)
    {
        str = '0' + str;
    }
}

void InsertSqlValue::PrintData(fstream &fo)
{
    for (auto line : listData)
    {
        int i = 0;
        fo << "(";
        for (auto word : SplitString(line, ','))
        {
            FormatString(word);
            if (column[i] == 0 && i < n_column - 1)
                fo << word << ", ";
            else if (column[i] == 0)
                fo << word;

            if (column[i] == 1 && i < n_column - 1)
                fo << "'" << word << "', ";
            else if (column[i] == 1)
                fo << "'" << word << "'";

            if (column[i] == 2)
            {
                insertZero(word);
                if (i < n_column - 1)
                    fo << "'" << word << "', ";
                else
                    fo << "'" << word << "'";
            }
            i++;
        }
        fo << ")," << endl;
    }
}

InsertSqlValue::~InsertSqlValue()
{
    delete[] column;
}