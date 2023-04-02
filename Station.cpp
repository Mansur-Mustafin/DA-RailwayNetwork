//
// Created by musta on 13.03.2023.
//

#include "Station.h"
#include <sstream>
int Station::getInd() {
    return ind;
}

string Station::getName() {
    return name;
}

string Station::getDistrict() {
    return district;
}

string Station::getMunicipality() {
    return municipality;
}

string Station::getTownship() {
    return township;
}

string Station::getLine() {
    return line;
}

int Station::getNumberStations() {
    return number_stations;
}

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

void Station::setInd(int x) {
    ind = x;
}

void Station::addNumberStations(int add) {
    number_stations += add;
}
