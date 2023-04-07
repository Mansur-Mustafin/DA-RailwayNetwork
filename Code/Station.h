/**
 * @file Station.h
 * @author Mansur Mustafin
 * @date 13.03.2023
 * @brief Declaration of class Station to load station data.
 */

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
    /**
    * This function returns the index of the given Station.
    * @return an integer with the index of the given Station.
    */
    int getInd() const;

    /**
    * This function alters the value of the index of the Station to the value of the given parameter x.
    * @param newInd - Value to which the index of the Station should be altered to
    */
    void setInd(int NewInd);

    /**
    * This function returns the name of the given Station.
    * @return a string with the name of the given Station.
    */
    string getName();

    /**
    * This function returns the District to which the given Station belongs.
    * @return a string with the District of the given Station.
    */
    string getDistrict();

    /**
    * This function returns the Municipality to which the given Station belongs.
    * @return a string with the Municipality of the given Station.
    */
    string getMunicipality();

    /**
    * This function returns the Township to which the given Station belongs.
    * @return a string with the Township of the given Station.
    */
    string getTownship();

    /**
    * This function returns the Train Line to which the given Station belongs.
    * @return a string with the line of the given Station.
    */
    string getLine();

    /**
     * Constructor of the class Station with the given parameters name, district, municipality, township, line.
     * @param name - Name of the Station
     * @param district - District of the Station
     * @param municipality - Municipality of the Station
     * @param township - Township of the Station
     * @param line - Line of the Station
     */
    Station(string name, string district, string municipality, string township, string line)
            : name(name), district(district), municipality(municipality), township(township), line(line){};

    /**
     * Default constructor of the class Station.
     */
    Station() = default;

    /**
    * This function returns the number of other Stations that have a connection to the given Station.
    * @return an integer with the number of other Stations connected to the given Station.
    */
    int getNumberStations() const;

    /**
    * This function increments the number of Stations connected to the Station by the value of parameter add.
    * @param add - Value that should be added to the variable number_stations of the Station
    */
    void addNumberStations(int add);

    /**
    * This operator specifies how an object of the class Station should be altered, given an input stream.
    * @param in - Input Stream
    * @param vertex - Station that should be altered
    * @return input stream containing the name, district, municipality, township and line of the Station.
    */
    friend istream &operator>>(istream &in, Station &vertex);

    /**
    * This operator specifies how an object of the class Station should be written into an output stream.
    * @param out - Output Stream
    * @param vertex - Station that should be written into the output stream
    * @return output stream containing the name, district, municipality, township and line of the Station.
    */
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
