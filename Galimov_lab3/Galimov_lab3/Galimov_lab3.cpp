#include <iostream>
#include <string>
#include <locale>
#include <fstream>
#include <set>
#include "Truba.h"
#include "KS.h"
#include "Utils.h"
#include "Maps.h"
#include "Connections.h"

using namespace std;

//общее для труб и КС
void view_all(map<int, Truba>& maptr, map<int, KS>& mapks)
{
    print_tr_all(maptr);
    print_ks_all(mapks);
}

void load_all(map<int, Truba>& maptr, map<int, KS>& mapks)
{
    string satn_n;
    ifstream fin;
    int last, i, last2;
    cout << "Введите имя файла: ";
    cin >> satn_n;
    fin.open(satn_n, ios_base::in);
    fin >> Truba::Truba_Max_Id;
    fin >> KS::KS_Max_Id;
    Truba tr;
    KS ks;
    for (int i = 1; i <= Truba::Truba_Max_Id; i++)
    {
        tr.load_tr_n(fin, tr);
        maptr.insert(pair<int, Truba>(i, tr));
    }
    cout << "Трубы успешно загружены" << endl;
    for (int i = 1; i <= KS::KS_Max_Id; i++)
    {
        ks.load_ks_n(fin, ks);
        mapks.insert(pair<int, KS>(i, ks));
    }
    cout << "КС успешно загружены" << endl;
}

void save_all(map<int, Truba>& maptr, map<int, KS>& mapks)
{
    string satn_n;
    ofstream fout;
    int last, i, last2;
    cout << "Введите имя файла: ";
    cin >> satn_n;
    fout.open(satn_n, ios_base::out);
    fout << maptr.size() << endl;
    fout << mapks.size() << endl;
    Truba tr;
    KS ks;
    for (auto& tr_out : maptr)
    {
        tr.save_tr_n(fout, tr_out.second);
    }
    cout << "Трубы успешно сохранены" << endl;
    for (auto& ks_out : mapks)
    {
        ks.save_ks_n(fout, ks_out.second);
    }
    cout << "КС успешно сохранены" << endl;
}



void vibor(Truba tr, KS ks, map<int, Truba>& maptr, map<int, KS>& mapks, map<int, Connections>mapcon) //бесконечное меню
{
    int s = 0, nt = 0, nk = 0;
    string ks_name;
    double pnc = 0.0;
    do {
        print_menu();
        GetCorrectNumber(s, 0, 8);
        switch (s)
        {
        case 1:
        {
            Truba tr;
            cin >> tr;
            add_tr(maptr, tr);
            break;
        }
        case 2:
        {
            KS ks;
            cin >> ks;
            add_ks(mapks, ks);
            break;
        }
        case 3:
            view_all(maptr, mapks);
            break;
        case 4:
            choose_tr(maptr);
            break;
        case 5:
            choose_ks(mapks);
            break;
        case 6:
            save_all(maptr, mapks);
            break;
        case 7:
            load_all(maptr, mapks);
            break;
        case 8:
            menu_choose_connections(maptr,mapks,mapcon);
            break;
        }
    } while (s != 0);
}

int main() //красиво и лаконично
{
    setlocale(LC_ALL, "Russian");
    Truba tr;
    KS ks;
    Connections con;
    map<int, Truba> maptr;
    map<int, KS> mapks;
    map<int, Connections>mapcon;
    
    set<int> settr;
    set<int>setks;
    vibor(tr, ks, maptr, mapks,mapcon);
}
