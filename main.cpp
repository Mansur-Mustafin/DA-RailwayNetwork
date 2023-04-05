#include "Code/Graph.h"
#include "Code/Menu.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {

    try {
        Menu menu;
        menu.choose_network();
    }
    catch (exception& e) {
        cout << e.what() << '\n';
    }

//    Graph g = Graph("network_test_4.csv", "stations_test_4.csv");
//    vector<string> base = {"A","E"}; // A -> E (D)
//    g.Task2_3(base, 10, false);

    //cout << g.Task2_4_3(base) << endl;

    return 0;
}
