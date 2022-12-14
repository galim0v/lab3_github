#include "KS.h"
#include "Utils.h"
#include <iostream>
#include <string>
#include <locale>
#include <fstream>
#include <map>
#include <set>


using namespace std;

int KS::KS_Max_Id = 1;

int KS::GetId()
{
    return id;
}

void KS::SetEffect(double effect)
{
    this->effect = effect;
}

double KS::GetEffect()
{
    return effect;
}

string KS::GetName()
{
    return name;
}

void KS::load_ks_n(ifstream& fin, KS& ks)
{
    getline(fin >> ws, ks.name);
    fin >> ks.id;
    fin >> ks.kolceh;
    fin >> ks.kolcehjob;
    fin >> ks.effect;
}

void KS::save_ks_n(ofstream& fout, KS& ks)
{
    fout << ks.name << endl;
    fout << ks.id << endl;
    fout << ks.kolceh << endl;
    fout << ks.kolcehjob << endl;
    fout << ks.effect << endl;
}

istream& operator>> (istream& in, KS& ks)
{
    ks.id = KS::KS_Max_Id++;

    cout << "������� �������� �� � " << ks.id << ":" << endl;

    getline(cin >> ws, ks.name);// �� ���������� ������ ����� � �����, ����� ws ���������� ����, �� ������

    cout << "������� ���-�� ����� �� � " << ks.id << ":" << endl;
    GetCorrectNumber(ks.kolceh, 0, 1000000);

    cout << "������� ���-�� ����� � ������ �� � " << ks.id << ":" << endl;
    GetCorrectNumber(ks.kolcehjob, 0, ks.kolceh);

    ks.effect = ((static_cast<double>(ks.kolcehjob)) / ks.kolceh) * 100;//����� ������� ������� � ��������� �������, �� ���� ��� ������� ���-�� ������������
    cout << "������������� ��: " << ks.effect << "%" << endl;

    cout << endl;

    return in;
}

ostream& operator<< (ostream& out, KS& ks)
{
    cout << "����� ��: " << ks.id << endl;
    cout << "��� ��: " << ks.name << endl;
    cout << "���-�� ����� ��: " << ks.kolceh << endl;
    cout << "���-�� ����� � ������ ��: " << ks.kolcehjob << endl;
    cout << "������������� ��: " << ks.effect << "%" << endl << endl;

    return out;
}


