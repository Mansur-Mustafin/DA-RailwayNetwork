/**
 * @file Railway.h
 * @author Mansur Mustafin
 * @date 13.03.2023
 * @brief Declaration of class Railway to load railway data.
 */

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
    /**
    * This function returns Station A of a given Railway.
    * @return a string with the station A (or number 1) of the given Railway.
    */
    string getStationA() const;

    /**
    * This function returns Station B of a given Railway.
    * @return a string with the Station B of the given Railway.
    */
    string getStationB() const;

    /**
    * This function returns the capacity of a given Railway.
    * @return an integer with the value equal to the capacity of the given Railway.
    */
    int getCapacity() const;

    /**
    * This function returns the type of service of a given Railway.
    * @return a string with the type of service of the given Railway.
    */
    string getService() const;

    /**
    * This function returns the flow of a given Railway.
    * @return an integer with the value equal to the flow of the given Railway.
    */
    int getFlow() const;

    /**
    * This function returns the previous position of a given Railway.
    * @return an integer with the value equal to the previous position of the given Railway.
    */
    int getPrevPosition() const;

    /**
    * This function returns the cost of a given Railway.
    * @return an integer with the value equal to the cost of the given Railway.
    */
    int getCost() const;

    /**
    * This function alters the previous position of the Railway to the value of the given parameter newPosition.
    * @param newPosition
    */
    void setPrevPosition(int newPosition);

    /**
    * This function alters the capacity of the Railway to the value of the given parameter newCapacity.
    * @param newCapacity
    */
    void setCapacity(int newCapacity);

    /**
    * This function alters Station A of the Railway to the Station given by the parameter stationA.
    * @param stationA
    */
    void setStationA(const string& stationA);

    /**
    * This function alters Station B of the Railway to the Station given by the parameter stationB.
    * @param stationB
    */
    void setStationB(const string& stationB);

    /**
    * This functions sets the service of the Railway to the service given by parameter service_.
    * @param service_
    */
    void setService(string service);

    /**
    * This function alters the cost of the Railway to the value given by the parameter c.
    * @param c
    */
    void setCost(int c);

    /**
    * This function increments the flow of the Railway by the value of the given parameter delta.
    * @param delta
    */
    void addFlow(int delta);

    /**
    * This function decrements the flow of the Railway by the value of the given parameter delta.
    * @param delta
    */
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

    /**
    * This operator specifies how an object of the class Railway should be altered, given an input stream.
    * @param in
    * @param edge
    * @return input stream containing the stations, capacity, service and cost of the Railway.
    */
    friend istream &operator>>(istream &is, Railway &edge);

    /**
    * This operator specifies how an object of the class Railway should be written into an output stream.
    * @param in
    * @param edge
    * @return output stream containing the stations, capacity, service and flow of the Railway.
    */
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
