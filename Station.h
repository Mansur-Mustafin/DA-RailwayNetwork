//
// Created by musta on 13.03.2023.
//

#ifndef DA_RAILWAYNETWORK_STATION_H
#define DA_RAILWAYNETWORK_STATION_H

#include <string>
using namespace std;
class Station {
public:
    int getInd();
    void setInd(int NewInd);
    string getName();
    string getDistrict();
    string getMunicipality();
    string getTownship();
    string getLine();
    int getNumberStations();
    void addNumberStations(int add);
    friend istream &operator>>(istream &in, Station &vertex);
    friend ostream &operator<<(ostream &out, const Station &vertex);
private:
    int ind = 0;
    string name;
    string district;
    string municipality;
    string township;
    string line;
    int number_stations;
};


#endif //DA_RAILWAYNETWORK_STATION_H
