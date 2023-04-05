//
// Created by musta on 15.03.2023.
//

#ifndef DA_RAILWAYNETWORK_GRAPH_H
#define DA_RAILWAYNETWORK_GRAPH_H


#include "Railway.h"
#include "Station.h"
#include <string>
#include <unordered_map>
#include <vector>

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
    int dfs(int v, int t, int current_min, vector<bool> &mark, vector<Railway> &rail);
    pair<int, vector<int>> dijkstra(int s, int t, vector<Railway> &edgesList);
    void minCostFlow(int s, int t, vector<Railway> &rail);
    bool check_keys(const vector<string> &base);
    bool check_segments(const vector<int> &seg);
    vector<vector<int>> adjacencyList;
    vector<Railway> railways;
    vector<Station> stations;                     // stations
    unordered_map<string, int> key;               // name -> index in vector
    string input_edge_name = "network.csv";
    string input_vertex_name = "stations.csv";
    void input_vertex(const string &input_name);
    void input_edge(const string &input_name);
    void build_adjacencyList();
    int ford_falk(int s, int t, vector<Railway> &rail, int skip = -1);
    int edmonds_karp(int s, int t, int u, vector<Railway> &rail, int skip = -1);
    int bfs(int s, int t, int u, vector<Railway> &rail, vector<int> &mark);
    int bfs_priority(int s, int t, int u, vector<Railway> &rail, vector<int> mark);
public:
    void add_station(const string& name, bool f = true, const string& district = "", const string& municipality = "", const string& township = "", const string& line = ""); // f : write to file?
    void add_railway(const string& nameA, const string& nameB, bool f = true, int capacity = 1e9, const string& service = "STANDARD");
    int getIndexOfRailway(pair<string, string>);
    int Task2_1(const vector<string> &base);
    int Task2_1_2(const vector<string> &from, const vector<string> &to);
    int Task2_1_3(const vector<string> &base);
    void Task2_2(vector<string> &base);
    void Task2_2_2();
    void Task2_3(vector<string> &base, int k, bool flag);
    void Task2_3_2(vector<string> &base, int k, bool flag);
    int Task3_1(const vector<string> &base);
    Graph(const string &input_edge_name, const string &input_vertex_name);
    void Task2_4(const vector<string> &station);
    int Task2_4_2(const string &station);
    int Task2_4_3(const vector<string> &base);
    int Task4_1(const vector<string> &base, const vector<int> &reduce);
    int Task4_1_2(const vector<string> &base, const vector<string> &name_of_stations);
    int Task4_2(const vector<string> &base, const vector<int> &reduce, int k);
    void printImage();
};


#endif //DA_RAILWAYNETWORK_GRAPH_H