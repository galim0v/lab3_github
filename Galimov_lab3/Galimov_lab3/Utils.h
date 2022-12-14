#pragma once
#include <iostream>
using namespace std;

template <typename T>
T GetCorrectNumber(T& x, T min, T max)
{
    cin >> x;
    while (cin.fail() || x<min || x>max)
    {
        cout << "¬ведено некорректное значение" << endl << "ƒиапазон: " << min << "-" << max << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> x;
    }
    return x;
}

void print_menu();//почему он не предлагает соззать в cpp сразу как было в трубе и кс


void print_menu_choose_tr();

void print_menu_choose_tr2();

void print_menu_edit_tr();


void print_menu_choose_ks();

void print_menu_choose_ks2();

void print_menu_edit_ks();



