#pragma once
#include <iostream>
#include <string>
#include <locale>
#include <fstream>
#include <set>
#include <map>
#include "Truba.h"
#include "KS.h"
#include "Utils.h"
#include "Maps.h"

using namespace std;

class Connections
{
public:
	int tr_id=0,
		ks_start_id=0,
		ks_end_id=0;
};

void add_connection(map<int, Truba>& maptr, map<int, KS>& mapks, map<int, Connections>& mapcon);

void view_connections(map<int, Connections>& mapcon);
