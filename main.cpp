#include "Code/Graph.h"
#include "Code/Menu.h"
#include <iostream>

using namespace std;

int main() {

    try {
        Menu menu;
        //menu.choose_network();
    }
    catch (exception& e) {
        cout << e.what() << '\n';
    }

    Graph g = Graph("network.csv", "stations.csv");
//    vector<string> base = {"Porto Campanhã","Espinho"}; // A -> E (D)
    vector<int> reduce = {485};
    g.Task4_2_2(reduce, 10);
//    Graph::printImage();
//    //g.Task3_1(base);

    return 0;
}
