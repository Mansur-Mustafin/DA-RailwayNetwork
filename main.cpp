#include "Code/Graph.h"
#include "Code/Menu.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {

    try {
        Menu menu;
        //menu.choose_network();
    }
    catch (exception& e) {
        cout << e.what() << '\n';
    }

    Graph g = Graph("network_test_4.csv", "stations_test_4.csv");
    vector<string> base = {"A","E","D"}; // A -> E (D)
    //vector<int> reduce = {504};
    cout << g.Task2_4_3(base);


    //Graph g = Graph("Tests/network.csv", "Tests/stations.csv");
    //vector<string> base = {"Porto Campanhã" , "Vila Nova de Gaia-Devesas"}; // A -> E (D)
    //cout << g.Task3_1(base);

    return 0;
}
