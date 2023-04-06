//
// Created by fgonc on 01/04/2023.
//

#ifndef DA_RAILWAYNETWORK_MENU_H
#define DA_RAILWAYNETWORK_MENU_H


#include "Graph.h"

/**
 * @brief Class implemented with functions to develop a user interface
 *
 * This class represents a menu with its several options, each responsible for creating part of the user interface and
 * managing the requests made by the user
 */
class Menu {
public:
    void main_menu();
    void choose_network();
    void add_station();
    void add_railway();
    void change_file();
    void Task2_1();
    //void Max_flow();
    void Task2_1_2();
    //void Max_flow_between_two_groups();
    void Task2_2();
    //void Heaviest_edge();
    void Task2_2_2();
    //void All_pairs_with_maxflow();
    void Task2_3();
    void Task2_3_2();
    void Task2_4();
    //void Number_of_trains_that_enter_a_station_with_max_flow();
    void Task2_4_2();
    //void Max_number_of_trains_that_can_enter_a_station();
    void Task2_4_3();
    //void Max_number_of_trains_that_can_enter_a_station_with_max_flow();
    void Task3_1();
    //void Max_trains_between_two_stations_with_min_cost();
    void Task4_1();
    void Task4_1_2();
    void Task4_2();
private:
    Graph g = Graph("network_test_4.csv", "stations_test_4.csv");
};


#endif //DA_RAILWAYNETWORK_MENU_H
