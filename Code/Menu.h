//
// Created by fgonc on 01/04/2023.
//

#ifndef DA_RAILWAYNETWORK_MENU_H
#define DA_RAILWAYNETWORK_MENU_H

#endif //DA_RAILWAYNETWORK_MENU_H

#include "Graph.h"

class Menu {
public:
    void main_menu();
    void choose_network();
    void add_station();
    void add_railway();
    void Task2_1();
    void Task2_1_2();
    void Task2_2();
    void Task2_2_2();
    void Task2_3();
    void Task2_3_2();
    void Task2_4();
    void Task2_4_2();
    void Task2_4_3();
    void Task3_1();
    void Task4_1();
    void Task4_1_2();
    void Task4_2();
    void basic_service();
    void operation_cost();
    void line_failures();
    void add_stations_raiwlyas();

private:
    Graph g = Graph("network_test_1.csv", "stations_test_1.csv");
};
