//
// Created by musta on 13.03.2023.
//

#include "Railway.h"
#include <iostream>
/**
 * This boolean function determines if the string contains only numbers
 * @param s
 * @return True if the string is a number. False if the string is empty or contains characters that don't represent numbers
 */
bool is_number(const string &s) {
    for (char x : s) {
        if (x < '0' || x > '9') {
            return false;
        }
    }
    return !s.empty();
}

/**
 * This operator specifies how an object of the class Railway should be altered, given an input stream
 * @param in
 * @param edge
 * @return input stream containing the stations, capacity, service and cost of the Railway
 */
istream &operator>>(istream &in, Railway &edge) {
    getline(in, edge.station_A, ',');
    getline(in, edge.station_B, ',');
    string s;
    getline(in, s, ',');
    if (is_number(s)) {
        edge.capacity = stoi(s);
    } else {
        return in;
    }
    getline(in, edge.service);
    edge.cost = (edge.service == "STANDARD") ? 1 : 2;
    return in;
}

/**
 * This operator specifies how an object of the class Railway should be written into an output stream
 * @param in
 * @param edge
 * @return output stream containing the stations, capacity, service and flow of the Railway
 */
ostream &operator<<(ostream &out, const Railway &edge) {
    out << edge.station_A << " ";
    out << edge.station_B << " ";
    out << edge.capacity << " ";
    out << edge.flow << " ";
    out << edge.service;
    return out;
}
/**
 * This function returns Station A of a given Railway
 * @return a string with the station A (or number 1) of the given Railway
 */
string Railway::getStationA() const {
    return station_A;
}

/**
 * This function returns Station B of a given Railway
 * @return a string with the Station B of the given Railway
 */
string Railway::getStationB() const {
    return station_B;
}

/**
 * This function returns the capacity of a given Railway
 * @return an integer with the value equal to the capacity of the given Railway
 */
int Railway::getCapacity() const {
    return capacity;
}

/**
 * This function returns the type of service of a given Railway
 * @return a string with the type of service of the given Railway
 */
string Railway::getService() const {
    return service;
}

/**
 * This function returns the flow of a given Railway
 * @return an integer with the value equal to the flow of the given Railway
 */
int Railway::getFlow() const {
    return flow;
}

/**
 * This function returns the previous position of a given Railway
 * @return an integer with the value equal to the previous position of the given Railway
 */
int Railway::getPrevPosition() const {
    return prev_position;
}

/**
 * This function returns the cost of a given Railway
 * @return an integer with the value equal to the cost of the given Railway
 */
int Railway::getCost() const {
    return cost;
}

/**
 * This function alters the previous position of the Railway to the value of the given parameter newPosition
 * @param newPosition
 */
void Railway::setPrevPosition(int newPosition) {
    prev_position = newPosition;
}

/**
 * This function alters the capacity of the Railway to the value of the given parameter newCapacity
 * @param newCapacity
 */
void Railway::setCapacity(int newCapacity) {
    capacity = newCapacity;
}

/**
 * This function increments the flow of the Railway by the value of the given parameter delta
 * @param delta
 */
void Railway::addFlow(int delta) {
    flow += delta;
}

/**
 * This function decrements the flow of the Railway by the value of the given parameter delta
 * @param delta
 */
void Railway::subFlow(int delta) {
    flow -= delta;
}

/**
 * This function alters Station A of the Railway to the Station given by the parameter stationA
 * @param stationA
 */
void Railway::setStationA(const std::string& stationA) {
    station_A = stationA;
}

/**
 * This function alters Station B of the Railway to the Station given by the parameter stationB
 * @param stationB
 */
void Railway::setStationB(const std::string& stationB) {
    station_B = stationB;
}

/**
 * This function alters the cost of the Railway to the value given by the parameter c
 * @param c
 */
void Railway::setCost(int c) {
    cost = c;
}

/**
 * This functions sets the service of the Railway to the service given by parameter service_
 * @param service_
 */
void Railway::setService(string service_) {
    service = service_;
}
