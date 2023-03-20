#include "Graph.h"
#include <iostream>


using namespace std;


int main() {
    Graph g = Graph("network.csv", "stations.csv");
    while (true) {
        vector<string> base(2);
        cout << "Enter name of station: <from> <to> \n";
        getline(cin, base[0]);
        getline(cin, base[1]);
        cout
                << "Enter number of task: <2_1> <2_2> <2_3> <2_4> <3_1> <4_1>, without "
                   "<> or enter <exit>\n";
        string number;
        getline(cin, number);
        if (number == "2_1") {
            cout << g.Task2_1(base);
        } else if (number == "2_2") {
            g.Task2_2(base);
        } else if (number == "3_1") {
            cout << g.Task3_1(base);
        } else if (number == "2_3") {
            // TODO
            g.Task2_3(base, 5, true);
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
