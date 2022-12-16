#pragma once
#include <iostream>
#include <string>
#include <locale>
#include <fstream>
#include "Connections.h"
#include <map>
#include <set>

using namespace std;

class KS
{
public:
    int static KS_Max_Id;
    string name = "-";

    friend ostream& operator<< (ostream& out, KS& ks);
    friend istream& operator>> (istream& in, KS& ks);
    int GetId();
    void SetEffect(double effect);
    string GetName();
    double GetEffect();
    void save_ks_n(ofstream& fout, KS& ks);
    void load_ks_n(ifstream& fin, KS& ks);

private:
    int id;

    int kolceh = 0, kolcehjob = 0;
    double effect = 0;
};

