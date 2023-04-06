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
    vector<string> base = {"Vila Nova de Gaia-Devesas","Lisboa Oriente"}; // A -> E (D)
    vector<int> reduce = {1,2, 498};
    g.Task4_2(base, reduce, 10);

    //cout << g.Task2_4_3(base) << endl;

    return 0;
}
