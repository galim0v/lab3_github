#include "Connections.h"

using namespace std;

void add_connection(map<int, Truba>& maptr, map<int, KS>& mapks, map<int, Connections>& mapcon)
{
    Connections con;

    cout << "������� id ��������� ��" << endl;
    cin >> con.ks_start_id;
    // GetCorrectNumber(con.ks_start_id, );

    cout << "������� id �������� ��" << endl;
    cin >> con.ks_end_id;
    //GetCorrectNumber(con.ks_end_id,);

    cout << "������� id �����, ������� �������� ��" << endl;
    cin >> con.tr_id;
    // GetCorrectNumber(con.tr_id, );

    mapcon.insert(pair<int, Connections>(con.tr_id, con));

}

void view_connections(map<int, Connections>& mapcon)
{
    for (auto& con_out : mapcon)
    {
        cout << "Id ��������� ��" << con_out.second.ks_start_id << endl;
        cout << "Id �����" << con_out.first << endl;
        cout << "Id �������� ��" << con_out.second.ks_end_id << endl;
    }
}