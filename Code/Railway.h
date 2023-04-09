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
    * @param newPosition - Value to which the previous position of the Railway should be altered to
    */
    void setPrevPosition(int newPosition);

    /**
    * This function alters the capacity of the Railway to the value of the given parameter newCapacity.
    * @param newCapacity - Value to which the capacity of the Railway should be altered to
    */
    void setCapacity(int newCapacity);

    /**
    * This function alters Station A of the Railway to the Station given by the parameter stationA.
    * @param stationA - New name of the Station A of the Railway
    */
    void setStationA(const string& stationA);

    /**
    * This function alters Station B of the Railway to the Station given by the parameter stationB.
    * @param stationB - New name of the Station B of the Railway
    */
    void setStationB(const string& stationB);

    /**
    * This functions sets the service of the Railway to the service given by parameter service_.
    * @param service_ - Type of service to which the current service of the Railway should be altered to
    */
    void setService(string service_);

    /**
    * This function alters the cost of the Railway to the value given by the parameter c.
    * @param c - Cost to which the current cost of the Railway should be altered to
    */
    void setCost(int c);

    /**
    * This function increments the flow of the Railway by the value of the given parameter delta.
    * @param delta - Value that should be added to the current flow of the Railway
    */
    void addFlow(int delta);

    /**
    * This function decrements the flow of the Railway by the value of the given parameter delta.
    * @param delta - Value that should be subtracted from the current flow of the Railway
    */
    void subFlow(int delta);

    /**
     * Constructor of the class Railway with the given parameters flow, to and prev_position.
     * @param flow - Flow of the Railway
     * @param to - Position to which the Railway should go
     * @param prev_position - Previous Position of the Railway
     */
    Railway(int flow, int to, int prev_position)
            : flow(flow), prev_position(prev_position){};

    /**
     * Default Constructor of the class Railway.
     */
    Railway() = default;

    /**
    * This operator specifies how an object of the class Railway should be altered, given an input stream.
    * @param in - Input Stream
    * @param edge - Railway that should be altered
    * @return input stream containing the stations, capacity, service and cost of the Railway.
    */
    friend istream &operator>>(istream &is, Railway &edge);

    /**
    * This operator specifies how an object of the class Railway should be written into an output stream.
    * @param ot - Output Stream
    * @param edge - Railway that should be printed into the terminal
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
