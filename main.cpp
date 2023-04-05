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

    Graph g = Graph("network_test_4.csv", "stations_test_4.csv");
    vector<string> base = {"A","E","D"}; // A -> E (D)
    cout << g.Task2_4_3(base);


    return 0;
}
