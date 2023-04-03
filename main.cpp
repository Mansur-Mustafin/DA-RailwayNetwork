#include "Graph.h"
#include <iostream>

using namespace std;

int main() {
    Graph g = Graph("network_test_3.csv", "stations_test_3.csv");

    //Graph g = Graph("network.csv", "stations.csv");
    while (true) {
        vector<string> base = {"A","E"};
        cout << "Enter number of task: <2_1> <2_1_2> <2_2> <2_2_2> <2_3> <2_4> <3_1> <4_1> <4_2>\n";
        string number;
        getline(cin, number);
        if (number == "2_1") {
            cout << g.Task2_1(base);
        } else if (number == "2_1_2") {
            vector<string> from = {"A"};
            vector<string> to = {"E"};
            g.Task2_1_2(from, to);
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
            int n;
            cin >> n;

            vector<int> reduce(n, 0);

            for (size_t i = 0; i < n; i++)
            {
                cin >> reduce[i];
            }

            cout << g.Task4_1(base, reduce);
        } else if (number == "4_2") {
            int n, k;
            cin >> n;

            vector<int> reduce(n, 0);

            for (size_t i = 0; i < n; i++)
            {
                cin >> reduce[i];
            }

            cin >> k;
            g.Task4_2(base, reduce, k);
        } else if (number == "exit") {
            break;
        } else {
            cerr << "Unknown command";
        }
        cout << "\n\n";
    }


}
