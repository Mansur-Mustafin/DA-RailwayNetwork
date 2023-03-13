//
// Created by musta on 13.03.2023.
//

#ifndef DA_RAILWAYNETWORK_RAILWAY_H
#define DA_RAILWAYNETWORK_RAILWAY_H
#include <string>

using namespace std;

class Railway {
public:
    int ind = 0;
    string station_A;
    string station_B;
    string capacity;
    string service;
    friend istream &operator>>(istream &is, Railway &edge);
    friend ostream &operator<<(ostream &ot, const Railway &edge);
};


#endif //DA_RAILWAYNETWORK_RAILWAY_H
