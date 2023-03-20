//
// Created by musta on 13.03.2023.
//

#ifndef DA_RAILWAYNETWORK_RAILWAY_H
#define DA_RAILWAYNETWORK_RAILWAY_H

#include <string>

using namespace std;
class Railway {
public:
    // int ind = 0;
    string station_A;
    string station_B;
    int capacity = 0;
    string service;
    int flow = 0;
    int prev_position = 0;
    int cost = 0;
    //  bool is_reverse = false;
    Railway(int flow, int to, int prev_position)
            : flow(flow), prev_position(prev_position){};
    Railway() = default;
    friend istream &operator>>(istream &is, Railway &edge);
    friend ostream &operator<<(ostream &ot, const Railway &edge);
};

#endif //DA_RAILWAYNETWORK_RAILWAY_H
