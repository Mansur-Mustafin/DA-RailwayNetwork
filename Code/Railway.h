//
// Created by musta on 13.03.2023.
//

#ifndef DA_RAILWAYNETWORK_RAILWAY_H
#define DA_RAILWAYNETWORK_RAILWAY_H

#include <string>

using namespace std;

/**
 *@brief Class representing a Railway.
 *
 * This class represents a Railway, with the stations it travels to and from, its capacity, type of service, flow,
 * previous position and cost.
 */
class Railway {
public:
    string getStationA() const;
    string getStationB() const;
    int getCapacity() const;
    string getService() const;
    int getFlow() const;
    int getPrevPosition() const;
    int getCost() const;
    void setPrevPosition(int newPosition);
    void setCapacity(int newCapacity);
    void setStationA(const string& stationA);
    void setStationB(const string& stationB);
    void setService(string service);
    void setCost(int c);
    void addFlow(int delta);
    void subFlow(int delta);

    /**
     * Constructor of the class Railway with the given parameters flow, to and prev_position.
     * @param flow
     * @param to
     * @param prev_position
     */
    Railway(int flow, int to, int prev_position)
            : flow(flow), prev_position(prev_position){};

    /**
     * Default Constructor of the class Railway.
     */
    Railway() = default;
    friend istream &operator>>(istream &is, Railway &edge);
    friend ostream &operator<<(ostream &ot, const Railway &edge);
private:
    string station_A;
    string station_B;
    int capacity = 0;
    string service;
    int flow = 0;
    int prev_position = 0;
    int cost = 0;
};

#endif //DA_RAILWAYNETWORK_RAILWAY_H
