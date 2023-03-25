#include "Graph.h"
#include <iostream>

using namespace std;

int main() {
    Graph g = Graph("network_test_1.csv", "stations_test_1.csv");
    //Graph g = Graph("network.csv", "stations.csv");

    while (true) {
        vector<string> base = {"A","N"};
        cout << "Enter number of task: <2_1> <2_2> <2_2_2> <2_3> <2_4> <3_1> <4_1>\n";
        string number;
        getline(cin, number);
        if (number == "2_1") {
            cout << g.Task2_1(base);
        } else if (number == "2_2") {
            g.Task2_2(base);
        } else if (number == "2_2_2") {
            g.Task2_2_2();
        } else if (number == "3_1") {
            cout << g.Task3_1(base);
        } else if (number == "2_3") {
            // TODO
            g.Task2_3(base, 10, false);
        } else if (number == "2_4") {
            string s;
            getline(cin, s);
            base.emplace_back(s);
            g.Task2_4(base);
        } else if (number == "4_1") {
            // TODO
        } else if (number == "exit") {
            break;
        } else {
            cerr << "Unknown command";
        }
        cout << "\n\n";
    }
}
