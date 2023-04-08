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
    vector<int> reduce = {464};
    //g.Task4_2_2(reduce, 15);
    g.Task4_2_3(100);

    return 0;
}
