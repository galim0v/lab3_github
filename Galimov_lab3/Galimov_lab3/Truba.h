#pragma once
#include <iostream>
#include <string>
#include <locale>
#include "Connections.h"
#include <fstream>
#include <map>
#include <set>

using namespace std;

class Truba
{
public:
    int static Truba_Max_Id;
    string name;
    // string sost = "-"; // тернарный оператор не хранить в структуре


    friend ostream& operator<< (ostream& out, Truba& tr);
    friend istream& operator>> (istream& in, Truba& tr);
    int GetId();
    void SetSostb(bool sostb);
    bool GetSostb();
    void save_tr_n(ofstream& fout, Truba& tr);
    void load_tr_n(ifstream& fin, Truba& tr);

private:
    int id = 0;
    double dlina = 0, diametr = 0;
    bool sostb = 0;
};

