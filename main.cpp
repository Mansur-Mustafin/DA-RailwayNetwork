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
    vector<string> base = {"Mato Miranda","Mato Miranda"}; // A -> E (D)
    cout << g.Task2_1_3(base) << endl;
    cout << g.Task2_1(base);

    return 0;
}
