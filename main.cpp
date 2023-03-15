#include "Graph.h"
#include <iostream>
using namespace std;

int main() {
    Graph g = Graph("network.csv", "stations.csv");
    vector<string> base(2);
    getline(cin, base[0]);
    getline(cin, base[1]);
    cout << g.Task2_1(base) << "\n";
    cout << g.Task3_1(base) << "\n";

    g.Task2_3(base, 5, true);
    cout << "\n";
    // g.Task2_2();
}
