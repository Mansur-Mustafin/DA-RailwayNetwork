//
// Created by musta on 13.03.2023.
//

#include "Station.h"
#include <iostream>
#include <sstream>

istream &operator>>(istream &in, Station &vertex) {
    getline(in, vertex.name, ',');
    getline(in, vertex.district, ',');
    getline(in, vertex.municipality, ',');
    getline(in, vertex.township, ',');
    getline(in, vertex.line);
    return in;
}

ostream &operator<<(ostream &out, const Station &vertex) {
    out << vertex.name << " ";
    out << vertex.district << " ";
    out << vertex.municipality << " ";
    out << vertex.township << " ";
    out << vertex.line << "\n";
    return out;
}