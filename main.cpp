#include "Code/Graph.h"
#include "Code/Menu.h"
#include <iostream>

using namespace std;

int main() {

    try {
        Menu menu;
        //menu.choose_network();
        menu.main_menu();
    }
    catch (exception& e) {
        cout << e.what() << '\n';
    }

//    Graph g = Graph("network.csv", "stations.csv");
//    vector<string> base = {"Porto Campanhã","Espinho"}; // A -> E (D)
//    vector<int> reduce = {485};
//    g.Task4_2(base, reduce, 10, true);
//    Graph::printImage();
//    //g.Task3_1(base);

    return 0;
}
