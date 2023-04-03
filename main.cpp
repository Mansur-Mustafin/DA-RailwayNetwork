#include "Code/Graph.h"
#include "Code/Menu.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {

    try {
        Menu menu;
        menu.main_menu();
    }
    catch (exception& e) {
        cout << e.what() << '\n';
    }

    return 0;

    //Graph g = Graph("Tests/network_test_3.csv", "Tests/stations_test_3.csv");
    //cout << g.getIndexOfRailway({"I","H"});
    //vector<string> reduce = {"B", "D"};
    //vector<string> base = {"A","E"};
    //cout << g.Task4_1_2(base, reduce);

//
//    g.printImage();
//
//    //Graph g = Graph("network.csv", "stations.csv");
//    while (true) {
//        vector<string> base = {"A","E"};
//        cout << "Enter number of task: <2_1> <2_1_2> <2_2> <2_2_2> <2_2_3> <2_3> <2_3_2> <2_4> <2_4_2> <3_1> <4_1> <4_1_2> <4_2>\n";
//        string number;
//        getline(cin, number);
//        if (number == "2_1") {
//            cout << g.Task2_1(base);
//        } else if (number == "2_1_2") {
//            vector<string> from = {"A"};
//            vector<string> to = {"E"};
//            cout << "Max Flow:" << g.Task2_1_2(from, to);
//        } else if (number == "2_2") {
//            g.Task2_2(base);
//        } else if (number == "2_2_2") {
//            g.Task2_2_2();
//        } else if (number == "2_2_2") {
//            vector<string> v = {"A", "E", "D"}; // A -> E (D).
//            cout << g.Task2_4_3(v);
//        } else if (number == "3_1") {
//            cout << g.Task3_1(base);
//        } else if (number == "2_3") {
//            // TODO
//            g.Task2_3(base, 10, false);
//        } else if (number == "2_3_2") {
//            g.Task2_3_2(base, 10, false);
//        } else if (number == "2_4") {
//            string s;
//            getline(cin, s);
//            base.emplace_back(s);
//            g.Task2_4(base);
//        } else if (number == "2_4_2") {
//            cout << g.Task2_4_2("Porto Campanhã");
//        } else if (number == "4_1") {
//            int n;
//            cin >> n;
//
//            vector<int> reduce(n, 0);
//
//            for (size_t i = 0; i < n; i++){
//                cin >> reduce[i];
//            }
//
//            cout << g.Task4_1(base, reduce);
//        } else if (number == "4_1_2") {
//            vector<string> reduce = {"B", "D"};
//
//            cout << g.Task4_1_2(base, reduce);
//        } else if (number == "4_2") {
//            int n, k;
//            cin >> n;
//
//            vector<int> reduce(n, 0);
//
//            for (size_t i = 0; i < n; i++){
//                cin >> reduce[i];
//            }
//
//            cin >> k;
//            g.Task4_2(base, reduce, k);
//        } else if (number == "exit") {
//            break;
//        } else {
//            cerr << "Unknown command";
//        }
//        cout << "\n\n";
//    }
}
