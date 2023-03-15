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

class Graph {
    int dfs(int v, int t, int current_min, vector<bool> &mark,
            vector<Railway> &rail);

    pair<int, vector<int>> dijkstra(int s, int t, vector<Railway> &edgesList);
    void minCostFlow(int s, int t, vector<Railway> &rail);
    bool check_keys(const vector<string> &base);
    // храниться номер станции, то есть кудо надо пойти, но по сути можно хранить
    // и номер ребра
    vector<vector<int>> adjacencyList;
    vector<Railway> railways;
    vector<Station> stations;
    unordered_map<string, int> key;
    void input_vertex(const string &input_name);
    void input_edge(const string &input_name);
    void build_adjacencyList();
    int ford_falk(int s, int t, vector<Railway> &rail);

public:
    int Task2_1(const vector<string> &base);
    void Task2_2(vector<string> &base);
    void Task2_3(vector<string> &base, int k, bool flag);
    int Task3_1(const vector<string> &base);
    Graph(const string &input_edge_name, const string &input_vertex_name);
};


#endif //DA_RAILWAYNETWORK_GRAPH_H
