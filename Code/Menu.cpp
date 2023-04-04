//
// Created by fgonc on 01/04/2023.
//

#include <iomanip>
#include <iostream>
#include "Menu.h"

using namespace std;

void Menu::choose_network(){
    string stations,network;
    cout<<"Do you want to change the network?:\n"
          "Press 1 if yes                     \n"
          "Press 2 if no                      \n";
    int answer;
    cin>>answer;
    cout<<endl;

    switch (answer) {
        case 1:
            cout<<"Please enter the name of the stations file with extension:\n";
            getline(cin>>ws,stations);
            cout<<endl;
            cout<<"Please enter the name of the network file with extension:\n";
            getline(cin,network);
            cout<<endl;
            g.set_input_edge_name(stations);
            g.set_input_vertex_name(network);
            if(g.get_input_edge_name()==stations && g.get_input_vertex_name()==network){
                cout<<"Done";
                main_menu();
            }
            break;

        case 2:
            main_menu();
            break;
    }
}

void Menu::add_station(){
    cout<<"Please enter the station name: \n";
    string name;
    getline(cin>>ws,name);
    cout<<endl;
    cout<<"Please enter the station district: \n";
    string distric;
    getline(cin,distric);
    cout<<endl;
    cout<<"Please enter the station municipality: \n";
    string municipality;
    getline(cin,municipality);
    cout<<endl;
    cout<<"Please enter the station township: \n";
    string township;
    getline(cin,township);
    cout<<endl;
    cout<<"Please enter the station line: \n";
    string line;
    getline(cin,line);
    cout<<endl;
    g.add_station(name,true,distric,municipality,township,line);
}

void Menu::add_railway(){
    cout<<"Please enter the source station name: \n";
    string source_name;
    getline(cin>>ws,source_name);
    cout<<endl;
    cout<<"Please enter the destination station name:\n";
    string dest_name;
    getline(cin,dest_name);
    cout<<"Please enter the railway capacity:\n";
    int capacity;
    cin>>capacity;
    cout<<"Please enter the railway service:\n";
    string service;
    getline(cin,service);
    g.add_railway(source_name, dest_name, true, capacity, service);
}

void Menu::Task2_1(){
    cout<<"Please enter the source station name: \n";
    string source_name;
    getline(cin>>ws,source_name);
    cout<<endl;
    cout<<"Please enter the destination station name:\n";
    string dest_name;
    getline(cin,dest_name);
    vector<string> base;
    base.emplace_back(source_name);
    base.emplace_back(dest_name);
    g.Task2_1(base);
}
void Menu::Task2_1_2(){
    int n;
    cout <<"How many source stations you want ?:\n";
    cin >> n;
    vector<string> source(n,"");
    for (size_t i = 0; i < n; i++){
        cout <<"Please enter the name of one source station:\n";
        getline(cin >>ws, source[i]);
    }

    cout <<"How many destination stations you want ?:\n";
    cin >> n;
    vector<string> destination(n,"");
    for (size_t i = 0; i < n; i++){
        cout <<"Please enter the name of one destination station:\n";
        getline(cin >>ws, destination[i]);
    }
    g.Task2_1_2(source,destination);
}

void Menu::Task2_2(){
    cout<<"Please enter the source station name: \n";
    string source_name;
    getline(cin>>ws,source_name);
    cout<<endl;
    cout<<"Please enter the destination station name:\n";
    string dest_name;
    getline(cin,dest_name);
    cout<<endl;
    vector<string> base;
    base.emplace_back(source_name);
    base.emplace_back(dest_name);
    g.Task2_2(base);
}

void Menu::Task2_2_2(){
    //cout<<"Please enter the source station name: \n";
    //string source_name;
    //getline(cin>>ws,source_name);
    //cout<<endl;
    //cout<<"Please enter the destination station name:\n";
    //string dest_name;
    //getline(cin,dest_name);
    //cout<<endl;
    //vector<string> base;
    //base.emplace_back(source_name);
    //base.emplace_back(dest_name);
    g.Task2_2_2();
}

void Menu::Task2_3(){
    cout<<"Please enter the source station name: \n";
    string source_name;
    getline(cin>>ws,source_name);
    cout<<endl;
    cout<<"Please enter the destination station name:\n";
    string dest_name;
    getline(cin,dest_name);
    cout<<endl;
    vector<string> base;
    base.emplace_back(source_name);
    base.emplace_back(dest_name);
    int number;
    cout<<"Please enter a number:\n";
    cin>>number;
    g.Task2_3(base,number,true);
}

void Menu::Task2_3_2(){
    cout<<"Please enter the source station name: \n";
    string source_name;
    getline(cin>>ws,source_name);
    cout<<endl;
    cout<<"Please enter the destination station name:\n";
    string dest_name;
    getline(cin,dest_name);
    cout<<endl;
    vector<string> base;
    base.emplace_back(source_name);
    base.emplace_back(dest_name);
    int number;
    cout<<"Please enter a number:\n";
    cin>>number;
    g.Task2_3_2(base,number,true);
}

void Menu::Task2_4(){
    cout<<"Please enter the source station name: \n";
    string source_name;
    getline(cin>>ws,source_name);
    cout<<endl;
    cout<<"Please enter the destination station name:\n";
    string dest_name;
    getline(cin,dest_name);
    cout<<endl;
    vector<string> base;
    base.emplace_back(source_name);
    base.emplace_back(dest_name);
    string station_name;
    cout<<"Please enter a station name:\n";
    cin>>station_name;
    base.push_back(station_name);
    g.Task2_4(base);
}

void Menu::Task2_4_2(){
    cout<<"Please enter the station name: \n";
    string name;
    getline(cin>>ws,name);
    cout<<endl;
    //cout<<"Please enter the destination station name:\n";
    //string dest_name;
    //getline(cin,dest_name);
    //cout<<endl;
    //vector<string> base;
    //base.emplace_back(source_name);
    //base.emplace_back(dest_name);
    //string station_name;
    //cout<<"Please enter a station name:\n";
    //cin>>station_name;
    //base.push_back(station_name);
    g.Task2_4_2(name);
}

void Menu::Task2_4_3(){
    //cout<<"Please enter the source station name: \n";
    //string source_name;
    //getline(cin>>ws,source_name);
    //cout<<endl;
    //cout<<"Please enter the destination station name:\n";
    //string dest_name;
    //getline(cin,dest_name);
    //cout<<endl;
    //vector<string> base;
    //base.emplace_back(source_name);
    //base.emplace_back(dest_name);
    //string station_name;
    //cout<<"Please enter a station name:\n";
    //cin>>station_name;
    //base.push_back(station_name);
    //g.Task2_4_3(base);
}

void Menu::Task3_1(){
    cout<<"Please enter the source station name: \n";
    string source_name;
    getline(cin>>ws,source_name);
    cout<<endl;
    cout<<"Please enter the destination station name:\n";
    string dest_name;
    getline(cin,dest_name);
    cout<<endl;
    vector<string> base;
    base.emplace_back(source_name);
    base.emplace_back(dest_name);
    g.Task3_1(base);
}

void Menu::Task4_1(){
    cout<<"Please enter the source station name: \n";
    string source_name;
    getline(cin>>ws,source_name);
    cout<<endl;
    cout<<"Please enter the destination station name:\n";
    string dest_name;
    getline(cin,dest_name);
    cout<<endl;
    vector<string> base;
    base.emplace_back(source_name);
    base.emplace_back(dest_name);
    int n;
    cout <<"How many segments you want to erase ?:\n";
    cin >> n;
    vector<int> reduce(n, 0);
    for (size_t i = 0; i < n; i++){
        cout <<"Please enter the index of one segment:\n";
        cin >> reduce[i];
    }
    g.Task4_1(base,reduce);
}

void Menu::Task4_1_2(){
    cout<<"Please enter the source station name: \n";
    string source_name;
    getline(cin>>ws,source_name);
    cout<<endl;
    cout<<"Please enter the destination station name:\n";
    string dest_name;
    getline(cin,dest_name);
    cout<<endl;
    vector<string> base;
    base.emplace_back(source_name);
    base.emplace_back(dest_name);
    int n;
    cout <<"How many stations u want to add ?:\n";
    cin >> n;
    vector<string> stations(n, 0);
    for (size_t i = 0; i < n; i++){
        cout <<"Please enter the name of one station:\n";
        cin >> stations[i];
    }
    g.Task4_1_2(base,stations);
}

void Menu::Task4_2(){
    cout<<"Please enter the source station name: \n";
    string source_name;
    getline(cin>>ws,source_name);
    cout<<endl;
    cout<<"Please enter the destination station name:\n";
    string dest_name;
    getline(cin,dest_name);
    cout<<endl;
    vector<string> base;
    base.emplace_back(source_name);
    base.emplace_back(dest_name);
    int number;
    cout<<"Please enter a number:\n";
    cin>>number;
    int n;
    cout <<"How many segments you want to erase ?:\n";
    cin >> n;
    vector<int> reduce(n, 0);
    for (size_t i = 0; i < n; i++){
        cout <<"Please enter the index of one segment:\n";
        cin >> reduce[i];
    }
    g.Task4_2(base,reduce,number);
}

void Menu::basic_service() {
    while (true) {
        cout << endl;
        cout
                << "|===========================================================================================================|\n"
                   "|                                               Basic Service                                               |\n"
                   "|===========================================================================================================|\n"
                   "| Maximum number of trains that can simultaneously travel between two  stations                     [21]    |\n"
                   "| Maximum number of trains that can simultaneously travel between two  stations (version 2)         [212]   |\n"
                   "| Pairs of stations that require the most amount amount of trains                                   [22]    |\n"
                   "| Pairs of stations that require the most amount amount of trains (version 2)                       [222]   |\n"
                   "| Top-k municipalities and districts, regarding their transportation needs                          [23]    |\n"
                   "| Top-k municipalities and districts, regarding their transportation needs (version 2)              [232]   |\n"
                   "| Maximum number of trains that can simultaneously arrive at a station                              [24]    |\n"
                   "| Maximum number of trains that can simultaneously arrive at a station (version 2)                  [242]   |\n"
                   "| Maximum number of trains that can simultaneously arrive at a station (version 3)                  [243]   |\n"
                   "|==================================================|========================================================|\n"
                   "|               Other operations                   |                                                         \n"
                   "|==================================================|                                                         \n"
                   "|  Back                                   [0]      |                                                         \n"
                   "|==================================================|                                                         \n";

        cout << endl;
        cout << "Please choose an option:";
        int option;
        cin >> option;
        cout << endl;

        if (cin.fail() || cin.peek() != '\n') {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Invalid input" << endl;
            continue;
        }

        switch (option) {
            case 0:
                main_menu();
                break;

            case 21:
                Task2_1();
                break;

            case 212:
                Task2_1_2();
                break;

            case 22:
                Task2_2();
                break;

            case 222:
                Task2_2_2();
                break;

            case 23:
                Task2_3();
                break;

            case 232:
                Task2_3_2();
                break;

            case 24:
                Task2_4();
                break;

            case 242:
                Task2_4_2();
                break;
            case 243:
                Task2_4_3();
                break;
        }
    }
}

void Menu::operation_cost(){
    while (true) {
        cout << endl;
        cout
                <<"|===========================================================================================================|\n"
                  "|                                               Operation Cost                                              |\n"
                  "|==================================================|========================================================|\n"
                  "| Maximum amount of trains that can simultaneously travel between two stations with minimum cost    [31]    |\n"
                  "|==================================================|========================================================|\n"
                  "|               Other operations                   |                                                         \n"
                  "|==================================================|                                                         \n"
                  "|  Back                                   [0]      |                                                         \n"
                  "|==================================================|                                                         \n";

        cout << endl;
        cout << "Please choose an option:";
        int option;
        cin >> option;
        cout << endl;

        if (cin.fail() || cin.peek() != '\n') {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Invalid input" << endl;
            continue;
        }

        switch (option) {
            case 0:
                main_menu();
                break;

            case 31:
                Task3_1();
                break;
        }
    }
}

void Menu::line_failures() {
    while (true) {
        cout << endl;
        cout
                << "|===========================================================================================================|\n"
                   "|                                               Line Failures                                               |\n"
                   "|===========================================================================================================|\n"
                   "| Maximum number of trains that can simultaneously travel between two stations in a reduced network [41]    |\n"
                   "| Maximum number of trains that can simultaneously travel between two stations in a reduced network [412]   |\n"
                   "| Top-k most affected stations for each segment failure                                             [42]    |\n"
                   "|==================================================|========================================================|\n"
                   "|               Other operations                   |                                                         \n"
                   "|==================================================|                                                         \n"
                   "|  Back                                   [0]      |                                                         \n"
                   "|==================================================|                                                         \n";
        cout << endl;
        cout << "Please choose an option:";
        int option;
        cin >> option;
        cout << endl;
        if (cin.fail() || cin.peek() != '\n') {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Invalid input" << endl;
            continue;
        }

        switch (option) {
            case 0:
                main_menu();
                break;

            case 41:
                Task4_1();
                break;

            case 412:
                Task4_1_2();
                break;

            case 42:
                Task4_2();
                break;

            default:
                cout << "Invalid input" << endl;

        }
    }
}

void Menu::add_stations_raiwlyas() {
    while (true) {
        cout << endl;
        cout
                << "|==================================================|\n"
                   "|               Add Stations/Railways              |\n"
                   "|==================================================|\n"
                   "| Add stations to the network             [11]      |\n"
                   "| Add railways to the network             [12]      |\n"
                   "|==================================================|\n"
                   "|               Other operations                   |\n"
                   "|==================================================|\n"
                   "|  Back                                   [0]      |\n"
                   "|==================================================|\n";
        cout << endl;
        cout << "Please choose an option:";
        int option;
        cin >> option;
        cout << endl;
        if (cin.fail() || cin.peek() != '\n') {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Invalid input" << endl;
            continue;
        }

        switch (option) {
            case 0:
                main_menu();

            case 11:
                add_station();
                break;

            case 12:
                add_railway();
                break;

        }
    }
}

void Menu::main_menu() {

    while (true) {
        cout << endl;
        cout
        << "|==================================================|\n"
           "|             Add Stations/Railways       [1]      |\n"
           "|==================================================|\n"
           "|                Basic Service            [2]      |\n"
           "|==================================================|\n"
           "|                Operation Cost           [3]      |\n"
           "|==================================================|\n"
           "|                Line Failures            [4]      |\n"
           "|==================================================|\n"
           "|                    Exit                 [0]      |\n"
           "|==================================================|\n";
        cout << endl;
        cout << "Please choose an option:";
        int option;
        cin >> option;
        cout << endl;
        if (cin.fail() || cin.peek() != '\n') {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Invalid input" << endl;
            continue;
        }

        switch (option) {
            case 0:
                exit(0);
            case 1:
                add_stations_raiwlyas();
                break;

            case 2:
                basic_service();
                break;

            case 3:
                operation_cost();
                break;

            case 4:
                line_failures();
                break;
            default:
                cout << "Invalid input" << endl;

        }

    }

}
