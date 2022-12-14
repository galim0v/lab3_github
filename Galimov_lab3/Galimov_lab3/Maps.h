#pragma once
#include "Truba.h"
#include "Utils.h"
#include "KS.h"
#include <iostream>
#include <string>
#include <locale>
#include <fstream>
#include <map>
#include <set>
#include "Connections.h"


using namespace std;

void add_tr(map<int, Truba>& maptr, Truba& tr);

void delete_tr(map<int, Truba>& maptr, set<int>& settr);

void print_tr_all(map<int, Truba>& maptr);

void edit_tr(map<int, Truba>& maptr, set<int>& settr);

void search_tr_sost(map<int, Truba>& maptr, set<int>& settr);

void search_tr_vvod(map<int, Truba>& maptr, set<int>& settr);

void search_tr_name(map<int, Truba>& maptr, set<int>& settr);

void print_choose_tr(map<int, Truba>& maptr, set<int>& settr);


void edit_delete_tr(map<int, Truba>& maptr, set<int>& settr);

void choose_tr_2(map<int, Truba>& maptr, set<int>& settr);

void choose_tr(map<int, Truba>& maptr);



void add_ks(map<int, KS>& mapks, KS& ks);

void delete_ks(map<int, KS>& mapks, set <int>& setks);

void print_ks_all(map<int, KS>& mapks);

void edit_ks(map<int, KS>& mapks, set <int>& setks);

void search_ks_name(map<int, KS>& mapks, set <int>& setks);

void search_ks_nezceh(map<int, KS>& mapks, set <int>& setks);

void print_choose_ks(map <int, KS>& mapks, set <int>& setks);

void search_ks_vvod(map <int, KS>& mapks, set <int>& setks);


void edit_delete_ks(map<int, KS>& mapks, set <int>& setks);

void choose_ks_2(map<int, KS>& mapks, set <int>& setks);

void choose_ks(map<int, KS>& mapks);




void menu_choose_connections(map<int, Truba>& maptr, map<int, KS>& mapks, map<int, Connections>& mapcon);

