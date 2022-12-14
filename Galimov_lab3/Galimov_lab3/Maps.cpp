#include <iostream>
#include <string>
#include <locale>
#include <fstream>
#include <map>
#include <set>
#include "Maps.h"
#include "Truba.h"
#include "KS.h"
#include "Utils.h"

using namespace std;

void add_tr(map<int, Truba>& maptr, Truba& tr)
{
    maptr.insert(pair<int, Truba>(tr.GetId(), tr));
}

void delete_tr(map<int, Truba>& maptr, set<int>& settr)
{
    for (auto& trId : settr)
    {
        maptr.erase(trId);
    }
    cout << "��������� ����� �������" << endl;

    settr.clear();
}

void print_tr_all(map<int, Truba>& maptr)
{
    if (maptr.size() == 0)
    {
        cout << "����� �� ���������/�� ���������" << endl;
    }
    else
    {
        for (auto& truba : maptr)
        {
            cout << truba.second;
        }
    }
}

void edit_tr(map<int, Truba>& maptr, set<int>& settr)
{
    if (maptr.size() == 0 || settr.size() == 0)
    {
        cout << "����� �� ���������/�� ���������" << endl;
    }
    else
    {
        bool sostb;

        cout << "�������� ��������� �����(0- � �������, 1- � ������): ";
        GetCorrectNumber(sostb, bool(0), bool(1));

        for (auto& trId : settr)
        {
            if (maptr.find(trId) != maptr.end())
            {
                maptr[trId].SetSostb(sostb);
                //maptr[trId].sost = (sostb == 1) ? "� ������" : "� �������";
                //cout << "��������� �����: " << (tr.sostb == 1) ? "� ������" : "� �������";
            }
            else
            {
                cout << "������ �� ������" << endl;
            }
        }
    }
}



void search_tr_sost(map<int, Truba>& maptr, set<int>& settr)
{
    settr.clear();
    bool tr_sost;

    cout << "������� ������� ��������� ����(0- � �������, 1- � ������)" << endl;

    GetCorrectNumber(tr_sost, bool(0), bool(1));

    cout << "������ ����: ";
    for (auto& tr : maptr)
    {
        if (tr.second.GetSostb() == tr_sost)
        {
            cout << tr.first << " ";
            settr.insert(tr.first);
        }
    }
    if (settr.size() == 0)
    {
        cout << "-" << endl;
        cout << "����� �� �������" << endl;
    }
    cout << endl;
}

void search_tr_vvod(map<int, Truba>& maptr, set<int>& settr)
{
    set<int> idcopy = settr;
    int s = 0, pr;
    settr.clear();

    cout << "������� ������ ����, ������� ������ ���������������(������� 0, ����� ��������� ����): " << endl;
    GetCorrectNumber(pr, 0, Truba::Truba_Max_Id); //pr-����� ��������
    while (pr != 0)
    {
        //����� �������� �� ���������� ��������
        if (idcopy.find(pr) == idcopy.end())//���� �� ����� � �������������� ���������,�� ��� � �� ����
        {
            cout << "����� �� ������ � �������������� ������������" << endl;
            (settr.size() == idcopy.size()) ? pr = 0 : GetCorrectNumber(pr, 0, Truba::Truba_Max_Id);
        }
        else//���� �� ����� ��
        {
            if (settr.find(pr) != settr.end())//�������� �� ������������   ���� ���� ������� ���� ���
            {
                cout << "����� ��� ��������" << endl;
                (settr.size() == idcopy.size()) ? pr = 0 : GetCorrectNumber(pr, 0, Truba::Truba_Max_Id);
            }
            else
            {
                settr.insert(pr);
                cout << "����� �������" << endl;
                (settr.size() == idcopy.size()) ? pr = 0 : GetCorrectNumber(pr, 0, Truba::Truba_Max_Id);
            }
        }
        if (pr == 0)
            cout << "������������ ����� �������" << endl;
    }
}

void search_tr_name(map<int, Truba>& maptr, set<int>& settr)
{
    settr.clear();
    string tr_name;
    cout << "������� ������� ��� ����" << endl;
    getline(cin >> ws, tr_name);
    cout << "������ ����: ";
    for (auto& tr : maptr)
    {
        if (tr.second.name.find(tr_name) != string::npos) //(it->second.name <= tr_name) //https://translated.turbopages.org/proxy_u/en-ru.ru.00528444-637a4949-b10949b2-74722d776562/https/stackoverflow.com/questions/2340281/check-if-a-string-contains-a-string-in-c
        {
            cout << tr.first << " ";
            settr.insert(tr.first);
        }
    }
    if (settr.size() == 0)
    {
        cout << "-" << endl;
        cout << "����� �� �������" << endl;
    }
    cout << endl;
}

void print_choose_tr(map<int, Truba>& maptr, set<int>& settr)
{
    if (settr.size() == 0)
    {
        cout << "����� �� �������" << endl;
    }
    else
    {
        for (auto& trId : settr)
        {
            cout << maptr[trId] << endl;
        }
    }
}



void edit_delete_tr(map<int, Truba>& maptr, set<int>& settr)
{
    int s;
    int last = settr.size();
    if (last == 0)
    {
        cout << "����� �� �������" << endl;
    }
    else
    {
        do {
            print_menu_edit_tr();
            GetCorrectNumber(s, 0, 2);
            switch (s)
            {
            case 1:
                edit_tr(maptr, settr);
                break;
            case 2:
                delete_tr(maptr, settr);
                break;
            }
        } while (s != 0);
    }
}

void choose_tr_2(map<int, Truba>& maptr, set<int>& settr)
{
    int s;
    int last = settr.size();

    if (last == 0)

    {
        cout << "����� �� �������" << endl;
    }
    else
    {

        do {
            print_menu_choose_tr2();
            GetCorrectNumber(s, 0, 3);
            switch (s)
            {
            case 1:
                print_choose_tr(maptr, settr);
                break;
            case 2:
                search_tr_vvod(maptr, settr);
                break;
            case 3:
                edit_delete_tr(maptr, settr);
                break;
            }
        } while (s != 0);
    }
}

void choose_tr(map<int, Truba>& maptr)
{
    set <int> settr;
    int s;
    int last = maptr.rbegin()->first;//������ ����� ��������� id ���������

    if (last == 0)
    {
        cout << "����� �� ���������/�� ���������" << endl;
    }
    else
    {
        do {
            print_menu_choose_tr();
            GetCorrectNumber(s, 0, 4);
            switch (s)
            {
            case 1:
                print_tr_all(maptr);
                break;
            case 2:
                search_tr_sost(maptr, settr);
                break;
            case 3:
                search_tr_name(maptr, settr);
                break;
            case 4:
                choose_tr_2(maptr, settr);
                break;
            }
        } while (s != 0);
    }
}








void add_ks(map<int, KS>& mapks, KS& ks)
{
    mapks.insert(pair<int, KS>(ks.GetId(), ks));//�������� ������� � ������ id
}

void delete_ks(map<int, KS>& mapks, set<int>& setks)
{
    for (auto& ksId : setks)
    {
        mapks.erase(ksId);
    }
    cout << "��������� �� �������" << endl;

    setks.clear();
}

void print_ks_all(map<int, KS>& mapks)
{
    if (mapks.size() == 0)
    {
        cout << "�� �� ���������/�� ���������" << endl;
    }
    else
    {
        for (auto& ks : mapks)
        {
            cout << ks.second;
        }
    }
}

void edit_ks(map<int, KS>& mapks, set<int>& setks)
{
    if (mapks.size() == 0 || setks.size() == 0)
    {
        cout << "�� �� ���������/�� ���������" << endl;
    }
    else
    {
        double effect;

        cout << "�������� ������������� ��: ";
        GetCorrectNumber(effect, 0.0, 100000.0);

        for (auto& ksId : setks)
        {
            if (mapks.find(ksId) != mapks.end())
            {
                mapks[ksId].SetEffect(effect);
            }
            else
            {
                cout << "������ �� ������" << endl;
            }
        }
    }
}


void search_ks_name(map<int, KS>& mapks, set<int>& setks)
{
    setks.clear();
    string ks_name;

    cout << "������� ��� ������� ��: ";
    getline(cin >> ws, ks_name);

    cout << "������ ��: ";

    for (auto& ks : mapks)
    {
        if (ks.second.name.find(ks_name) != string::npos) //(it->second.name == ks_name)  it->second.name.find(ks_name) != string::npos
        {
            cout << ks.first << " ";
            setks.insert(ks.first);
        }
    }

    if (setks.size() == 0)
    {
        cout << "-" << endl;
        cout << "�� �� �������" << endl;
    }
    cout << endl;
}

void search_ks_nezceh(map<int, KS>& mapks, set<int>& setks)
{
    setks.clear();
    double pnc;
    cout << "������� ������� �������� ����������������� �����" << endl;
    cin >> pnc;

    cout << "������ ��: ";
    for (auto& ks : mapks)
    {
        if (ks.second.GetEffect() == pnc)
        {
            cout << ks.first << " " << endl;
            setks.insert(ks.first);
        }
    }

    if (setks.size() == 0)
    {
        cout << "-" << endl;
        cout << "�� �� �������" << endl;
    }
}

void print_choose_ks(map<int, KS>& mapks, set<int>& setks)
{
    if (setks.size() == 0)
    {
        cout << "�� �� �������" << endl;
    }
    else
    {
        for (auto& ksId : setks)
        {
            cout << mapks[ksId];
        }
    }
}

void search_ks_vvod(map<int, KS>& mapks, set<int>& setks)
{
    set<int> idkscopy = setks;
    int s = 0, pr;
    setks.clear();

    cout << "������� ������ ��, ������� ������ ���������������(������� 0, ����� ��������� ����): " << endl;
    GetCorrectNumber(pr, 0, KS::KS_Max_Id); //pr-����� ��������
    while (pr != 0)
    {
        //����� �������� �� ���������� ��������
        if (idkscopy.find(pr) == idkscopy.end())//���� �� ����� � �������������� ���������,�� ��� � �� ����
        {
            cout << "�� �� ������ � �������������� ������������" << endl;
            (setks.size() == idkscopy.size()) ? pr = 0 : GetCorrectNumber(pr, 0, KS::KS_Max_Id);
        }
        else//���� �� ����� ��
        {
            if (setks.find(pr) != setks.end())//�������� �� ������������   ���� ���� ������� ���� ���
            {
                cout << "�� ��� ���������" << endl;
                (setks.size() == idkscopy.size()) ? pr = 0 : GetCorrectNumber(pr, 0, KS::KS_Max_Id);
            }
            else
            {
                setks.insert(pr);
                cout << "�� �������" << endl;
                (setks.size() == idkscopy.size()) ? pr = 0 : GetCorrectNumber(pr, 0, KS::KS_Max_Id);
            }
        }
    }

    if (pr == 0)
        cout << "������������ �� �������" << endl;

}


void edit_delete_ks(map<int, KS>& mapks, set <int>& setks)
{
    int s;
    int last = setks.size();
    if (last == 0)
    {
        cout << "�� �� �������" << endl;
    }
    else
    {
        do {
            print_menu_edit_ks();
            GetCorrectNumber(s, 0, 2);
            switch (s)
            {
            case 1:
                edit_ks(mapks, setks);
                break;
            case 2:
                delete_ks(mapks, setks);
                break;
            }
        } while (s != 0);
    }
}

void choose_ks_2(map<int, KS>& mapks, set <int>& setks)
{
    int s;
    int last = setks.size();
    if (last == 0)
    {
        cout << "�� �� �������" << endl;
    }
    else
    {
        do {
            print_menu_choose_ks2();
            GetCorrectNumber(s, 0, 3);
            switch (s)
            {
            case 1:
                print_choose_ks(mapks, setks);
                break;
            case 2:
                search_ks_vvod(mapks, setks);
                break;
            case 3:
                edit_delete_ks(mapks, setks);
                break;
            }
        } while (s != 0);
    }
}

void choose_ks(map<int, KS>& mapks)
{
    set <int> setks;
    int s;

    int last = mapks.rbegin()->first;//������ ����� ��������� id ���������

    if (last == 0)
    {
        cout << "�� �� ���������/�� ���������" << endl;
    }
    else
    {
        do {
            print_menu_choose_ks();

            GetCorrectNumber(s, 0, 4);

            switch (s)
            {
            case 1:
                print_ks_all(mapks);
                break;
            case 2:
                search_ks_name(mapks, setks);
                break;
            case 3:
                search_ks_nezceh(mapks, setks);
                break;
            case 4:
                choose_ks_2(mapks, setks);
                break;
            }
        } while (s != 0);
    }
}