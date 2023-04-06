#include "Code/Graph.h"
#include "Code/Menu.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {

//    try {
//        Menu menu;
//        menu.choose_network();
//    }
//    catch (exception& e) {
//        cout << e.what() << '\n';
//    }

    Graph g = Graph("network.csv", "stations.csv");
    vector<string> base = {"Porto Campanhã","Lisboa Oriente"}; // A -> E (D)
    vector<int> reduce = {1,2, 498};
    //g.Task4_2(base, reduce, 10);

    g.Task3_1(base);

    return 0;
}
