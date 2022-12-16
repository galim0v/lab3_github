#include "Truba.h"
#include "Connections.h"
#include "Utils.h"
#include <iostream>
#include <string>
#include <locale>
#include <fstream>
#include <map>
#include <set>

using namespace std;

int Truba::Truba_Max_Id = 1;

int Truba::GetId()
{
    return id;
}

void Truba::SetSostb(bool sostb)
{
    this->sostb = sostb;
}

void Truba::save_tr_n(ofstream& fout, Truba& tr)
{
    fout << tr.name << endl;
    fout << tr.id << endl;
    fout << tr.dlina << endl;
    fout << tr.diametr << endl;
    fout << tr.sostb << endl;
}

void Truba::load_tr_n(ifstream& fin, Truba& tr)
{
    getline(fin >> ws, tr.name);
    fin >> tr.id;
    fin >> tr.dlina;
    fin >> tr.diametr;
    fin >> tr.sostb;
}

bool Truba::GetSostb()
{
    return sostb;
}


istream& operator>> (istream& in, Truba& tr)
{
    tr.id = Truba::Truba_Max_Id++;

    cout << "Введите имя трубы № " << tr.id << ":" << endl;
    getline(in >> ws, tr.name);

    cout << "Введите длину трубы № " << tr.id << ":" << endl;
    GetCorrectNumber(tr.dlina, 0.0, 10000000.0);

    cout << "Введите диаметр трубы № " << tr.id << ":" << endl;
    GetCorrectNumber(tr.diametr, 0.0, 10000000.0);

    cout << "Введите состояние трубы(0-в ремонте, 1- в работе) № " << tr.id << ":" << endl;
    GetCorrectNumber(tr.sostb, bool(0), bool(1));

    //tr.sost = (tr.sostb == 1) ? "В работе" : "В ремонте";

    cout << endl;

    return in;
}

ostream& operator<< (ostream& out, Truba& tr)
{
    out << "Номер трубы: " << tr.id << endl;
    out << "Имя трубы: " << tr.name << endl;
    out << "Длина трубы: " << tr.dlina << endl;
    out << "Диаметр трубы: " << tr.diametr << endl;
    out << "Состояние трубы: " << ((tr.GetSostb() == true) ? "В работе" : "В ремонте");
    cout << endl << endl;
    return out;
}

