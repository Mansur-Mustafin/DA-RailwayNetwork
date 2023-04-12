#include "Code/Graph.h"
#include "Code/Menu.h"
#include <iostream>

using namespace std;

int main() {

    try {
        //Menu menu;
        //menu.choose_network();
    }
    catch (exception& e) {
        cout << e.what() << '\n';
    }

    Graph g = Graph("network_test_7.csv", "stations_test_7.csv");
    string input;
    vector<string> base = {"A", "E"};
    //g.Task2_1(base);
    //g.Task2_1_2({"A", "D"}, {"E"});
    //g.Task2_1_3(base);
    //g.Task2_2(base);
    //g.Task2_2_2();
    //g.Task2_3(base, 10, true);  // true - Municipality
    //g.Task2_3_2(base, 10, true);
    //g.Task2_4({"A", "E", "D"});
    //g.Task2_4_2("D", true);
    //g.Task2_4_3({"A", "E", "H"});
    //g.Task3_1(base);
    //g.Task4_1(base, {2,3});
    //g.Task4_1_2(base, {"I"});
    //g.Task4_2(base, {1,2}, 10);
    //g.Task4_2_2({2,3,4}, 10);
    //g.Task4_2_3(10);


    return 0;
}
