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

    cout << "������� ��� ����� � " << tr.id << ":" << endl;
    getline(in >> ws, tr.name);

    cout << "������� ����� ����� � " << tr.id << ":" << endl;
    GetCorrectNumber(tr.dlina, 0.0, 10000000.0);

    cout << "������� ������� ����� � " << tr.id << ":" << endl;
    GetCorrectNumber(tr.diametr, 0.0, 10000000.0);

    cout << "������� ��������� �����(0-� �������, 1- � ������) � " << tr.id << ":" << endl;
    GetCorrectNumber(tr.sostb, bool(0), bool(1));

    //tr.sost = (tr.sostb == 1) ? "� ������" : "� �������";

    cout << endl;

    return in;
}

ostream& operator<< (ostream& out, Truba& tr)
{
    out << "����� �����: " << tr.id << endl;
    out << "��� �����: " << tr.name << endl;
    out << "����� �����: " << tr.dlina << endl;
    out << "������� �����: " << tr.diametr << endl;
    out << "��������� �����: " << ((tr.GetSostb() == true) ? "� ������" : "� �������");
    cout << endl << endl;
    return out;
}

