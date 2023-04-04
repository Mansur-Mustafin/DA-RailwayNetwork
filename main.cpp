#include "Code/Graph.h"
#include "Code/Menu.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {

    try {
        Menu menu;
        //menu.main_menu();
    }
    catch (exception& e) {
        cout << e.what() << '\n';
    }


    Graph g = Graph("Tests/network_test_3.csv", "Tests/stations_test_3.csv");
    vector<string> base = {"A","E", "D"}; // A -> E (D)
    cout << g.Task2_4_3(base);

    return 0;
}
