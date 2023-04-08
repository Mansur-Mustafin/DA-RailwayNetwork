#include "Code/Graph.h"
#include "Code/Menu.h"
#include <iostream>

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
    //vector<int> reduce = {464, 10, 11};
    vector<string> base = {"A", "E", "D"};
    g.Task2_4_3(base);

    //Graph g = Graph("network.csv", "stations.csv");
    //vector<int> reduce = {464};
    //g.Task4_2_2(reduce, 15);
    //g.Task4_2_3(100);

    return 0;
}
