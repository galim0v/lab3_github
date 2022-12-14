#pragma once
#include "Truba.h"
#include "KS.h"
#include "Utils.h"
#include "Maps.h"
using namespace std;

class Connections
{
public:
	int tr_id,ks_start_id,ks_end_id;
};

void add_connection(map<int, Truba>& maptr, map<int, KS>& mapks, map<int, Connections>& mapcon);

void view_connections(map<int, Connections>& mapcon);
