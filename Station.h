//
// Created by musta on 13.03.2023.
//

#ifndef DA_RAILWAYNETWORK_STATION_H
#define DA_RAILWAYNETWORK_STATION_H

#include <string>
using namespace std;
class Station {
public:
    int ind = 0;
    string name;
    string district;
    string municipality;
    string township;
    string line;
    int number_stations;
    friend istream &operator>>(istream &in, Station &vertex);
    friend ostream &operator<<(ostream &out, const Station &vertex);
};


#endif //DA_RAILWAYNETWORK_STATION_H
