//
// Created by musta on 13.03.2023.
//

#ifndef DA_RAILWAYNETWORK_STATION_H
#define DA_RAILWAYNETWORK_STATION_H

#include <string>
using namespace std;
/**
 * @brief Class representing a Train Station
 *
 * This class represents a Train Station with its name, district, municipality, township and line. Each Station
 * also has a unique index (represented by variable ind), used to have a more efficient way of finding each station
 * when these are part of a Graph.
 */

class Station {
public:
    int getInd() const;
    void setInd(int NewInd);
    string getName();
    string getDistrict();
    string getMunicipality();
    string getTownship();
    string getLine();

    /**
     * Constructor of the class Station with the given parameters name, district, municipality, township, line.
     * @param name
     * @param district
     * @param municipality
     * @param township
     * @param line
     */
    Station(string name, string district, string municipality, string township, string line)
            : name(name), district(district), municipality(municipality), township(township), line(line){};

    /**
     * Default constructor of the class Station.
     */
    Station() = default;
    int getNumberStations() const;
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
    int number_stations = 0;
};


#endif //DA_RAILWAYNETWORK_STATION_H
