#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "InsertSqlValue.h"

void Solve(fstream &fi, fstream &fo)
{
    InsertSqlValue ins;
    ins.GetDataToList(fi);
    ins.GetNumberOfColumn();
    if (ins.n_column)
    {
        ins.DefineColumn();
        ins.PrintData(fo);
    }
}
int main()
{
    fstream fi("inp.txt", ios::in);
    fstream fo("out.txt", ios::out);

    Solve(fi, fo);
    cout << "\nData has been formatted, please check result in file 'out.txt'";
    
    fo.close();
    fi.close();
    return 0;
}