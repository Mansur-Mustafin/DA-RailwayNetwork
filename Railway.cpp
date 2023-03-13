//
// Created by musta on 13.03.2023.
//

#include "Railway.h"
#include <sstream>
istream &operator>>(istream &in, Railway &edge) {
    getline(in, edge.station_A, ',');
    getline(in, edge.station_B, ',');
    getline(in, edge.capacity, ',');
    getline(in, edge.service);
    return in;
}
ostream &operator<<(ostream &out, const Railway &edge) {
    out << edge.station_A << " ";
    out << edge.station_B << " ";
    out << edge.capacity << " ";
    out << edge.service << "\n";
    return out;
}