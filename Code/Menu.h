/**
 * @file Menu.h
 * @author fgonc
 * @date 01/04/2023
 * @brief Declaration of class Menu to use all functionalities of functions in user-friendly format.
 */

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
    /**
     * This function develops the main menu of the user interface.
     */
    void main_menu();

    /**
     * This function develops a page of the user interface designed to alter the network being analysed.
     */
    void choose_network();

    /**
     * This function develops a page of the user interface designed to add a station to the current network.
     */
    void add_station();

    /**
     * This function develops a page of the user interface designed to add a railway to the current network.
     */
    void add_railway();

    /**
     * This function develops a page of the user interface designed to change the file from which the network is being
     * loaded.
     */
    void change_file();

    /**
     * This function develops a page of the user interface with the data given by the Task2_1 function defined in Graph.h (Max flow between two stations)
     */
    void Task2_1();
    //void Max_flow();

    /**
     * This function develops a page of the user interface with the data given by the Task2_1_2 function defined in Graph.h (Max flow between two sets of stations)
     */
    void Task2_1_2();
    //void Max_flow_between_two_groups();

    /**
     * This function develops a page of the user interface with the data given by the Task2_2 function defined in Graph.h (Heaviest edge or Railway with the highest ammount of trains)
     */
    void Task2_2();
    //void Heaviest_edge();

    /**
     * This function develops a page of the user interface with the data given by the Task2_2_2 function defined in Graph.h (Pairs of stations with max flow)
     */
    void Task2_2_2();
    //void All_pairs_with_maxflow();

    /**
     * This function develops a page of the user interface with the data given by the Task2_3 function defined in Graph.h (Top-k municipalities/districts with the most need for trains)
     */
    void Task2_3();

    /**
     * This function develops a page of the user interface with the data given by the Task2_3_2 function defined in Graph.h (Top-k municipalities/districts with the most need for trains and a limited ammount of trains in the network)
     */
    void Task2_3_2();

    /**
     * This function develops a page of the user interface with the data given by the Task2_4 function defined in Graph.h (Trains that arrive at a station when there is max flow)
     */
    void Task2_4();
    //void Number_of_trains_that_enter_a_station_with_max_flow();

    /**
     * This function develops a page of the user interface with the data given by the Task2_4_2 function defined in Graph.h (Trains that can arrive at a station)
     */
    void Task2_4_2();
    //void Max_number_of_trains_that_can_enter_a_station();

    /**
     * This function develops a page of the user interface with the data given by the Task2_4_3 function defined in Graph.h (Maximum number of trains that can arrive at a station in max flow)
     */
    void Task2_4_3();
    //void Max_number_of_trains_that_can_enter_a_station_with_max_flow();

    /**
     * This function develops a page of the user interface with the data given by the Task3_1 function defined in Graph.h (Maximum amount of trains between two stations at minimum cost)
     */
    void Task3_1();
    //void Max_trains_between_two_stations_with_min_cost();

    /**
     * This function develops a page of the user interface with the data given by the Task4_1 function defined in Graph.h (Maximum flow in the segments of a reduced network)
     */
    void Task4_1();

    /**
     * This function develops a page of the user interface with the data given by the Task4_1_2 function defined in Graph.h (Maximum flow in the stations of a reduced network)
     */
    void Task4_1_2();

    /**
     * This function develops a page of the user interface with the data given by the Task4_2 function defined in Graph.h (Top k most affected stations by each segment failure)
     */
    void Task4_2();
    void Task4_2_2();
    void Task4_2_2_aux_1();
    void Task4_2_2_aux_2();
private:
    Graph g = Graph("network_test_4.csv", "stations_test_4.csv");
    //Graph g = Graph("network.csv", "stations.csv");
};


#endif //DA_RAILWAYNETWORK_MENU_H
