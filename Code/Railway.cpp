//
// Created by musta on 13.03.2023.
//

#include "Railway.h"
#include <iostream>
/**
 * This boolean function determines if the string contains only numbers.
 *
 * The time complexity of this function is O(n).
 * @param s
 * @return True if the string is a number. False if the string is empty or contains characters that don't
 * represent numbers.
 */
bool is_number(const string &s) {
    for (char x : s) {
        if (x < '0' || x > '9') {
            return false;
        }
    }
    return !s.empty();
}

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

ostream &operator<<(ostream &out, const Railway &edge) {
    out << edge.station_A << " -> ";
    out << edge.station_B << " ";
    out << edge.flow << "/";
    out << edge.capacity << " (";
    out << edge.service << ")" << endl;
    return out;
}

string Railway::getStationA() const {
    return station_A;
}

string Railway::getStationB() const {
    return station_B;
}

int Railway::getCapacity() const {
    return capacity;
}

string Railway::getService() const {
    return service;
}

int Railway::getFlow() const {
    return flow;
}

int Railway::getPrevPosition() const {
    return prev_position;
}

int Railway::getCost() const {
    return cost;
}

void Railway::setPrevPosition(int newPosition) {
    prev_position = newPosition;
}

void Railway::setCapacity(int newCapacity) {
    capacity = newCapacity;
}

void Railway::addFlow(int delta) {
    flow += delta;
}

void Railway::subFlow(int delta) {
    flow -= delta;
}

void Railway::setStationA(const std::string& stationA) {
    station_A = stationA;
}

void Railway::setStationB(const std::string& stationB) {
    station_B = stationB;
}

void Railway::setCost(int c) {
    cost = c;
}

void Railway::setService(string service_) {
    service = service_;
}
