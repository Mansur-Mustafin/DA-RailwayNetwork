//
// Created by musta on 13.03.2023.
//

#include "Station.h"
#include <sstream>

/**
 * This function returns the index of the given Station.
 * @return an integer with the index of the given Station.
 */
int Station::getInd() const {
    return ind;
}

/**
 * This function returns the name of the given Station.
 * @return a string with the name of the given Station.
 */
string Station::getName() {
    return name;
}

/**
 * This function returns the District to which the given Station belongs.
 * @return a string with the District of the given Station.
 */
string Station::getDistrict() {
    return district;
}

/**
 * This function returns the Municipality to which the given Station belongs.
 * @return a string with the Municipality of the given Station.
 */
string Station::getMunicipality() {
    return municipality;
}

/**
 * This function returns the Township to which the given Station belongs.
 * @return a string with the Township of the given Station.
 */
string Station::getTownship() {
    return township;
}

/**
 * This function returns the Train Line to which the given Station belongs.
 * @return a string with the line of the given Station.
 */
string Station::getLine() {
    return line;
}

/**
 * This function returns the number of other Stations that have a connection to the given Station.
 * @return an integer with the number of other Stations connected to the given Station.
 */
int Station::getNumberStations() const {
    return number_stations;
}

/**
 * This operator specifies how an object of the class Station should be altered, given an input stream.
 * @param in
 * @param vertex
 * @return input stream containing the name, district, municipality, township and line of the Station.
 */
istream &operator>>(istream &in, Station &vertex) {
    getline(in, vertex.name, ',');
    getline(in, vertex.district, ',');
    getline(in, vertex.municipality, ',');
    getline(in, vertex.township, ',');
    getline(in, vertex.line);
    return in;
}

/**
 * This operator specifies how an object of the class Station should be written into an output stream.
 * @param out
 * @param vertex
 * @return output stream containing the name, district, municipality, township and line of the Station.
 */
ostream &operator<<(ostream &out, const Station &vertex) {
    out << vertex.name << " ";
    out << vertex.district << " ";
    out << vertex.municipality << " ";
    out << vertex.township << " ";
    out << vertex.line << "\n";
    return out;
}

/**
 * This function alters the value of the index of the Station to the value of the given parameter x.
 * @param x
 */
void Station::setInd(int x) {
    ind = x;
}

/**
 * This function increments the number of Stations connected to the Station by the value of parameter add.
 * @param add
 */
void Station::addNumberStations(int add) {
    number_stations += add;
}
