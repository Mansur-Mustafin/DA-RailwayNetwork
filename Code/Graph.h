/**
 * @file Graph.h
 * @author Mansur Mustafin
 * @date 15.03.2023
 * @brief Declaration of class Graph to store date of station and railways and manipulate with them.
 */

#ifndef DA_RAILWAYNETWORK_GRAPH_H
#define DA_RAILWAYNETWORK_GRAPH_H


#include "Railway.h"
#include "Station.h"
#include <string>
#include <unordered_map>
#include <vector>
#include <set>
#include <queue>

using namespace std;

/**
 * @brief Class representing a Graph with Stations as vertices and Railways as edges
 *
 * This class represents a Graph, where the vertices are the Train Stations and the edges are Railways. The graph saves
 * the Railways and Train Stations in two vectors, each with objects of classes Railways and Stations, respectively.
 *
 * This class has a vector of vectors of integers, used to organize the connections (or adjacencies) of the Stations.
 *
 * This class has an unordered map of strings and integers, where the strings represent the names of the Stations and the
 * integers represent the indexes, therefore allowing us to get the name of a station with its index.
 *
 * This class has two strings input_edge_name and input_vertex_name, used for inputting the wanted
 * Stations and/or Railways, using the functions input_vertex and input_edge.
 */
class Graph {
    /**
    * This function implements the Depth First Search algorithm on the Graph in order to find the maximum flow that can be
    * added between two vertices of the Graph.
    *
    * The time complexity of this function is O(E) where E represents the number of edges of the Graph.
    * @param v - Integer representing the index of the starting vertex
    * @param t - Integer representing the index of the target vertex
    * @param current_min - Integer representing the current minimum flow of the search
    * @param mark - Vector of boolean variables, where the index of each variable is the index of a vertex. If the variable
    * is true then it means the vertex with its index has been visited already.
    * @param rail - Vector of objects of the class Railway
    * @return 0 if the vertex v has been visited before, current_min if the vertex v is equal to vertex t and the maximum
    * flow that can be added otherwise.
    */
    int dfs(int v, int t, int current_min, vector<bool> &mark, vector<Railway> &rail);

    /**
    * This function implements the Dijkstra algorithm in order to find the shortest path between two vertices in a
    * Graph.
    *
    * The time complexity of this function is O((V+E) * log V) where V represents the number of vertices and E
    * represents the number of edges of the Graph.
    * @param s - Integer representing the index of the starting vertex
    * @param t - Integer representing the index of the target vertex
    * @param rail - Vector of objects of the class Railway
    * @return a pair of values: the minimum capacity along the path and a vector of edges representing the path.
    */
    pair<int, vector<int>> dijkstra(int s, int t, vector<Railway> &edgesList);

    /**
    * This function applies the Dijkstra's algorithm in order to find the shortest path from "source" vertex s to
    * "sink" vertex t that has positive capacity and adds the maximum flow possible along the path it chooses while
    * minimizing the cost.
    *
    * The time complexity of this function is O(E * (V+E) * log V) where E is the number of edges and
    * V is the number of vertices.
    * @param s - Integer representing the "source" Station
    * @param t - Integer representing the "target" Station
    * @param rail - Vector of objects of the class Railway
    */
    void minCostFlow(int s, int t, vector<Railway> &rail);

    /**
    * This function determines whether a vector containing the names of stations contains a name of a station that
    * does not belong to the unordered map key and therefore is not a valid name of a Station in the Graph.
    *
    * The time complexity of this function is O(n) where n is the number of elements of the vector base.
    * @param base - vector of strings, each being a name of a Station
    * @return true if all the names in the parameter base exist in the unordered map key of the Graph and false if at least
    * one of the names does not.
    */
    bool check_keys(const vector<string> &base);

    /**
    * This function determines whether a segment defined by a vector of integers belongs the Graph or not.
    *
    * The time complexity of this function is O(n).
    * @param seg - Vector of integers that represents a segment between stations. The integers of the vector represent
    * the stations indexes
    * @return false if the segment cannot exist in the Graph and true otherwise.
    */
    bool check_segments(const vector<int> &seg);

    /**
    * This function determines whether stations are connected in the graph or, in other words, whether if it is
    * possible to reach the stations in vector v1 from the stations in vector v2 and vice versa.
    *
    * The time complexity of this function is O(1).
    * @param v1 - Vector of strings number one, with the strings being the names of Stations
    * @param v2 - Vector of strings number two, with the strings being the names of Stations
    * @return true if the stations can reach each other and false if they cannot.
    */
    static bool check_Disjoint(const vector<string>& v1, const vector<string>& v2);

    /**
    * This function inserts the Stations (in this case as vertices) in the string input_name into the given Graph.
    *
    * The time complexity of this function is O(n) where n is the number of lines of the string input_name.
    * @param input_name - Name of the file containing the vertices (or stations) we want to insert into the Graph
    */
    void input_vertex(const string &input_name);

    /**
    * This function inserts the Railways (in this case as edges) in the string input_name into the given Graph.
    *
    * The time complexity of this function is O(n) where n is the number of lines of the string input_name.
    * @param input_name - Name of the file containing the edges (or railways) we want to insert into the Graph
    */
    void input_edge(const string &input_name);

    /**
    * This function inputs into the vector adjacencyList subvectors of two integers, that dictate which Stations
    * are connected to each other by analysing the vector of Railways. Each subvector has the index of Station A and
    * the index of Station B. This function also updates the number of stations for each station in the graph.
    *
    * The time complexity of this function is O(V + E) where V is the number of vertices (or stations) and
    * E is the number of edges (or railways) of the Graph.
    */
    void build_adjacencyList();

    /**
    * This function implements the Ford-Fulkerson algorithm on the Graph in order to find the maximum flow from a "source"
    * vertex represented by parameter s to a "sink" vertex represented by parameter t.
    *
    * The time complexity of this function is O(F * E) where F is the maximum flow and E is the number
    * of edges of the Graph.
    * @param s - Integer representing the index of the "Source" Station
    * @param t - Integer representing the index of the "Sink" Station
    * @param rail - Vector of Objects of the class Railway
    * @param skip -
    * @return an integer with the value of the maximum flow between the "source" vertex and the "sink" vertex.
    */
    int ford_falk(int s, int t, vector<Railway> &rail, int skip = -1);

    /**
    * This functions implements the Edmonds-Karp algorithm to determine the maximum flow in the Graph between a "source"
    * vertex given by s and a "target" vertex given by t.
    *
    * The time complexity of this function is O(V * E^2) where V is the number of vertices and E is the
    * number of edges of the Graph.
    * @param s - Integer representing the index of the "source" vertex
    * @param t - Integer representing the index of the "target" vertex
    * @param rail - Vector of objects of the class Railway
    * @return an integer with the maximum flow from s to t
    */
    int edmonds_karp(int s, int t, vector<Railway> &rail);

    /**
     * This functions implements the Edmonds-Karp algorithm to determine the maximum flow in the Graph between a "source"
     * vertex given by s and a "target" vertex given by t, while passing through an intermediate vertex u.
     *
     * The time complexity of this function is O(V * E^2) where V is the number of vertices and E is the
     * number of edges of the Graph.
     * @param s - Integer representing the index of the "source" vertex
     * @param t - Integer representing the index of the "target" vertex
     * @param u - Integer representing the index of the "intermediate" vertex
     * @param rail - Vector of objects of the class Railway
     * @return an integer with the maximum flow from s to t, while passing through an intermediate vertex u
     */
    int edmonds_karp_priority(int s, int t, int u, vector<Railway> &rail);

    /**
    * This function implements the Breadth First Search Algorithm to determine an augmenting path and the maximum flow that
    * can be "pushed" into this path between a "source" vertex and a "target" vertex.
    *
    * The time complexity of this function is O(E) where E is the number of edges of the Graph.
    * @param s - Integer representing the index of the "source" vertex
    * @param t - Integer representing the index of the "target" vertex
    * @param u - Integer representing the index of the "intermediate" vertex
    * @param rail - Vector of objects of the class Railway
    * @param mark - Vector of integers that signal whether a vertex has been visited or not
    * @return 0 if no path can be found between the source vertex and the target vertex and the maximum flow that can exists
    * in the path between the vertices.
    */
    int bfs(int s, int t, int u, vector<Railway> &rail, vector<int> &mark);

    /**
     * This function implements the Breadth First Search Algorithm to determine an augmenting path and the maximum flow that
     * can be "pushed" into this path between a "source" vertex and a "target" vertex while passing .
     *
     * The time complexity of this function is O(E * log E) where E is the number of edges of the Graph
     * @param s - Integer representing the index of the "source" vertex
     * @param t - Integer representing the index of the "target" vertex
     * @param u - Integer representing the index of the "intermediate" vertex
     * @param rail - Vector of objects of the class Railway
     * @param mark - Vector of integers that signal whether a vertex has been visited or not
     * @return 0 if no path is found between the source vertex and the target vertex while passing through the intermediate
     * vertex or an integer with value equal to the maximum flow that can exist between the vertex s and t, while passing
     * through the intermediate vertex u.
     */
    int bfs_priority(int s, int t, int u, vector<Railway> &rail, vector<int>& mark);

    vector<vector<int>> adjacencyList;
    vector<Railway> railways;
    vector<Station> stations;
    unordered_map<string, int> key;
    string input_edge_name = "network.csv";
    string input_vertex_name = "stations.csv";
public:
    /**
     * Constructor of the Class Graph.
     * @param input_edge_name_ - Name of the file containing the names of the Railways that will be used to build the Graph
     * @param input_vertex_name_ - Name of the file containing the names of the Stations that will be used to build the Graph
     */
    Graph(const string &input_edge_name, const string &input_vertex_name);

    /**
    * This function adds the Station of attributes given by the parameters to the vector stations.
    * If the boolean parameter f is true, then it will write the attributes of the Station into an output stream,
    * that can be used to write them into a file.
    *
    * The time complexity of this function is O(1).
    * @param name - Name of the station we want to add
    * @param f - Boolean variable to determine if the station should be written into a file
    * @param district - District of the station we want to add
    * @param municipality - Municipality of the station we want to add
    * @param township - Township of the station we want to add
    * @param line - Line of the station we want to add
    */
    void add_station(const string& name, bool f = true, const string& district = "", const string& municipality = "", const string& township = "", const string& line = ""); // f : write to file?

    /**
    * This function adds the Railway of attributes given by the parameters to the vector railways. After the railway is
    * added into the vector in both directions (Station A to Station B and vice versa), it will alter the adjacency list,
    * taking into account the new railways that were added.
    * If the boolean parameter f is true, then it will write the attributes of the Railway into an output stream,
    * that can be used to write them into a file.
    *
    * The complexity of this function is O(1).
    * @param nameA - Name of station A of the railway we want to add
    * @param nameB - Name of station B of the railway we want to add
    * @param f - Boolean variable to determine if the railway should be written into a file
    * @param capacity - Capacity of the railway we want to add
    * @param service - Type of service of the railway we want to add
    */
    void add_railway(const string& nameA, const string& nameB, bool f = true, int capacity = 1e9, const string& service = "STANDARD");

    /**
    * This function obtains the index of the Railway whose Stations' names are contained in the parameter n.
    *
    * The time complexity of this function is O(n).
    * @param n - pair of strings with the name of station A and station B of the pretended railway
    * @return an integer with value equal to the index of the pretended Railway, or -1 if the pretended Railway
    * is not found in the vector railways of the Graph.
    */
    int getIndexOfRailway(const pair<string, string>&);

    /**
    * This function determines the maximum flow between two stations.
    *
    * The time complexity of this function is O(E * F) where E is the number of edges (or Railways) and F is
    * the maximum flow that exists in the network.
    * @param base - Vector of two strings with each one being the name of one of the stations that were inputted
    * @return an integer with the maximum flow between two stations.
    */
    int Task2_1(const vector<string> &base, bool print = true);

    /**
    * This function determines the maximum flow between a group of "source" Stations and "sink" or "target" Stations.
    *
    * The time complexity of this function is O(V1 + V2 + E * F) where V1 is the number of vertices (or Stations) from,
    * V2 is the number of vertices (or Stations) to, E is the number of edges (or Railways) and F is the maximum
    * flow that exists in the network.
    * @param from - vector of strings with each string being the name of one "source" Stations
    * @param to - vector of strings with each string being the name of one "sink" Stations
    * @return an integer with the maximum flow between two stations.
    */
    int Task2_1_2(const vector<string> &from, const vector<string> &to, bool print = true);

    /**
     * This function determines the maximum flow between a two Stations, using the Edmonds-Karp Algorithm
     *
     * The time complexity of this function is O(V * E^2) where V is the number of vertices (or Stations) and E is the
     * number of edges (or Railways)
     * @param base  - Vector of two strings with each one being the name of one of the stations that were inputted
     * @return an integer with the maximum flow between two stations
     */
    int Task2_1_3(const vector<string> &base);

    /**
    * This function prints the stations whose Railway has the most number of trains in between two previously selected
    * Stations. The function also prints the respective flow of the Railway that it selects.
    *
    * The time complexity of this function is O(E * F) where E is the number of edges (or Railways) and
    * F is the maximum flow that exists in the network.
    * @param base - Vector of two strings with each one being the name of one of the stations that were inputted
    */
    void Task2_2(vector<string> &base);

    /**
    * This function prints the pairs of stations whose railways have the maximum flow, in other words, stations that require
    * the most amount of trains.
    *
    * The time complexity of this function is O(E * (F * (V^2) + log E)) where V is the number of vertices
    * (or Stations), E is the number of edges (or Railways) and F is the maximum flow that exists in the network.
    * The E * log E is given due to the sort function that has a time complexity of O(N log N) where N is the number of
    * elements that function has to sort.
    */
    void Task2_2_2();

    /**
    * This function prints which municipalities or districts have stations that require more trains, according to the
    * overall capacity of the stations and railways included in each municipality and/or district. This function takes two
    * stations that will be used as the starting and ending point of the network.
    *
    * The time complexity of this function is O(E * (F + log E)) or (E * F + E * log E) where E is the number
    * of edges (or Railways) and F is the maximum flow that exists in the network.
    * @param base - Vector of two strings with each one being the name of one of the stations that were inputted
    * @param k - Integer that determines how many municipalities or districts should be printed
    * @param flag - Boolean variable that determines whether the function should print the municipalities or the districts
    */
    void Task2_3(vector<string> &base, int k, bool flag);

    /**
    * This function prints which municipalities or districts have stations that require more trains, according to the
    * overall capacity of the stations and railways included in each municipality and/or district, but also taking into
    * account that the network has a limited number of trains, given by the total flow of all the railways in the network.
    * This function takes two stations that will be used as the starting and ending point of the network.
    *
    * The time complexity of this function is O(E * (F + E)) where E is the number of edges (or Railways)
    * and F is the maximum flow that exists in the network.
    * @param base - Vector of two strings with each one being the name of one of the stations that were inputted
    * @param k - Integer that determines how many municipalities or districts should be printed
    * @param flag - Boolean variable that determines whether the function should print the municipalities or the districts
    */
    void Task2_3_2(vector<string> &base, int k, bool flag);

    /**
    * This function prints the number of trains that get into a specific Station when there is maximum flow.
    *
    * The time complexity of this function is O(F * E) where E is the number of edges (or Railways) and F is
    * the maximum flow that exists in the network.
    * @param base - Vector of two strings with each one being the name of one of the stations that were inputted
    */
    void Task2_4(const vector<string> &station);

    /**
    * This function determines the number of trains that can get into a specific Station.
    *
    * The time complexity of this function is O(V + E * F) where V is the number of vertices
    * (or Stations), E is the number of edges (or Railways) and F is the maximum flow that exists in the network.
    * @param station - String containing the name of the station we want to analyse
    * @return an integer with the number of trains that can get into a Station.
    */
    int Task2_4_2(const string &station, bool print = true);

    /**
    * This function returns the maximum number of trains that would get into a specific station when there is maximum flow.
    *
    * The time complexity of this function is O(V * E^2) where V is the number of vertices (or Stations) and E is the
    * number of edges (or Railways)
    * @param base - Vector of two strings with each one being the name of one of the stations that were inputted
    * @return an integer with value equal to the number of trains that can get into a station when there is maximum flow.
    */
    int Task2_4_3(const vector<string> &base);

    /**
    * This function determines the maximum amount of trains that can simultaneously travel between two specific stations
    * with minimum cost. In other words, this function determines the minimum cost at which we can achieve maximum
    * flow between two stations
    *
    * The time complexity of this function is O(E * (V + E) * log V), derived from the use of the minCostFlow function
    * @param base - Vector of two strings with each one being the name of one of the stations that were inputted
    * @return an integer with the maximum number of trains that can travel simultaneously between two stations.
    */
    int Task3_1(const vector<string> &base);

    /**
    * This function determines the maximum flow in a group of segments of a reduced Graph.
    *
    * The time complexity of this function is O(F * R) where R is the number of elements of the reduced network.
    * R should be equal or less than the number of edges (or railways) of the full network.
    * @param base - Vector of two strings with each one being the name of one of the stations that were inputted
    * @param reduce - Vector of integers with the indexes of the railways that should be removed from the network
    * @return an integer with the maximum number of trains that can travel simultaneously between in a railway
    * of a subgraph (or reduced Graph).
    */
    int Task4_1(const vector<string> &base, const vector<int> &reduce);

    /**
    * This function determines the maximum number of trains that can travel between two specific stations of a reduced Graph.
    *
    * The time complexity of this function is O(S + F * R) where S is the number of stations we want to add to the network,
    * F is the maximum flow of the network and R is the number of elements of the reduced network.
    * @param base - Vector of two strings with each one being the name of the starting and ending stations that were inputted
    * @param name_of_stations - Vector of strings containing the name of the stations we want to add
    * @return an integer with the maximum number of trains that can travel simultaneously between two specific stations
    * of a subgraph (or reduced Graph).
    */
    int Task4_1_2(const vector<string> &base, const vector<string> &name_of_stations);

    /**
    * This function prints the stations that would have a more significant loss of flow (or traffic of trains) when each
    * segment of the network is deemed to be nonoperational.
    *
    * The time complexity of this function is O(R + F * E) where R is the number of elements of the reduced network.
    * R should be equal or less than the number of edges (or railways) of the full network.
    * @param base - Vector of two strings with each one being the name of the starting and ending stations that were inputted
    * @param reduce  - Vector of integers with the indexes of the railways that should be removed from the network
    * @param k - Number of top-k affected stations that should be printed
    * @return 0 if the code ran successfully and -1 otherwise.
    */
    int Task4_2(const vector<string> &base, const vector<int> &reduce, int k, bool f = false);// f: print new flow?

    int Task4_2_2(const vector<int> &reduce, int k);

    /**
    * This function writes an "image" contained in a text document into the terminal.
    *
    * The time complexity of this function is O(n) where n is the number of lines of the text file.
    */
    static void printImage(const string& file_name = "train_image.txt", bool f = false);

    /**
     * This function returns the name of the file where the attributes of the stations of the network are contained
     * @return a string with the name of the file
     */
    string getStationName();

    /**
     * This function returns the name of the file where the attributes of the railways of the network are contained
     * @return a string with the name of the file
     */
    string getNetworkName();

    /**
     * This function determines how a network (Graph) should be printed into the terminal
     */
    void printNetwork();

    /**
     * This function determines how Station(s) should be printed into the terminal
     */
    void printStations();

    /**
    * This operator specifies how a set of integers should be written into an output stream.
    *
    * @complexity The time complexity of this operator is O(n) where n is the number of elements of the set s.
    * @param out - Output stream where the set of integers will be written into
    * @param s - Set of integers
    * @return output stream with the integers contained in the parameter s.
    */
    friend ostream &operator<<(ostream &out, set<int> &s);

    /**
    * This operator specifies how a queue of objects of the class Railway should be written into an output stream.
    *
    * @complexity The time complexity of this operator is O(n) where n is the number of elements of the queue s.
    * @param out - Output stream where the queue of Railways will be written into
    * @param s - Queue of Railways
    * @return output stream with the Railways contained in the parameter s.
    */
    friend ostream &operator<<(ostream &out, queue<Railway> &s);
};


#endif //DA_RAILWAYNETWORK_GRAPH_H