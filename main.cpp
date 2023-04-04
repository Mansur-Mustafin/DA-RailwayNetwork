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


    Graph g = Graph("Tests/network.csv", "Tests/stations.csv");
    vector<string> base = {"Porto Campanhã" , "Vila Nova de Gaia-Devesas"}; // A -> E (D)
    cout << g.Task3_1(base);

    return 0;
}
