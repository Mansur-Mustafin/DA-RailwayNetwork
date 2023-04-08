//
// Created by fgonc on 01/04/2023.
//

#include <iomanip>
#include <iostream>
#include <climits>
#include "Menu.h"

using namespace std;


void Menu::change_file() {
    string stations,network;
    cout<<"Please enter the name of the stations file without extension:\n";
    getline(cin>>ws,stations);
    cout<<endl;
    cout<<"Please enter the name of the network file without extension:\n";
    getline(cin,network);
    cout<<endl;
    g = Graph(network + ".csv", stations + ".csv");
    main_menu();
}

void Menu::choose_network(){
    Graph::printImage();
    string stations,network;
    cout<<"          Do you want to change the network?\n"
          "|==================================================| \n"
          "|       Yes [1]                   Not  [2]         | \n"
          "|==================================================| " << endl;
    int answer;
    cin>>answer;
    cout<<endl;

    if (cin.fail() || cin.peek() != '\n') {
        cerr << "Invalid input" << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        choose_network();
    }

    switch (answer) {
        case 1:
            cout<<"Please enter the name of the stations file without extension:\n";
            getline(cin>>ws,stations);
            cout<<endl;
            cout<<"Please enter the name of the network file without extension:\n";
            getline(cin,network);
            cout<<endl;
            g = Graph(network + ".csv", stations + ".csv");
            main_menu();
            break;
        case 2:
            main_menu();
            break;
        default:
            cerr << "Invalid input" << endl << endl;
            choose_network();
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
    cout << "Maximum flow " << source_name << " -> " << dest_name << " is: ";
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
    cout << "Maximum flow is: ";
    g.Task2_1_2(source,destination);
}

void Menu::Task2_2() {
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
    getline(cin>>number,source_name);
    cout<<endl;
    cout<<"Search municipalities [0] or districts [1]\n";
    int choice;
    getline(cin>>choice,source_name);
    cout<<endl;
    if(choice){
        g.Task2_3(base,number,false);
    }else{
        g.Task2_3(base,number,true);
    }
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
    getline(cin>>number,source_name);
    cout<<endl;
    cout<<"Search municipalities [0] or districts [1]\n";
    int choice;
    getline(cin>>choice,source_name);
    cout<<endl;
    if(choice){
        g.Task2_3_2(base,number,false);
    }else{
        g.Task2_3_2(base,number,true);
    }
}

void Menu::Task2_4() {
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
    g.Task2_4_2(name);
}

void Menu::Task2_4_3() {
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
    g.Task2_4_3(base);
}

void Menu::Task3_1() {
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
    string source_reduce,destination_reduce;
    pair<string,string> railway;
    for (size_t i = 0; i < n; i++){
        cout <<"Please enter the name of one source station:\n";
        getline(cin>>ws,source_reduce);
        cout <<"Please enter the name of one destination station:\n";
        getline(cin,destination_reduce);
        railway.first = source_reduce;
        railway.second = destination_reduce;
        int index = g.getIndexOfRailway(railway);
        reduce[i] = index;
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
    vector<string> stations(n, "");
    string name_station;
    for (size_t i = 0; i < n; i++){
        cout <<"Please enter the name of one station:\n";
        getline(cin>>ws,name_station);
        stations[i] = name_station;
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
    string source_reduce,destination_reduce;
    pair<string,string> railway;

    for (size_t i = 0; i < n; i++){
        cout <<"Please enter the name of one source station:\n";
        getline(cin>>ws,source_reduce);
        cout <<"Please enter the name of one destination station:\n";
        getline(cin,destination_reduce);
        railway.first = source_reduce;
        railway.second = destination_reduce;
        int index = g.getIndexOfRailway(railway);
        reduce[i] = index;
    }

    g.Task4_2(base,reduce,number);
}

void Menu::Task4_2_2(){
    int number;
    cout<<"Please enter a number:\n";
    cin>>number;
    int n;
    cout <<"How many segments you want to erase ?:\n";
    cin >> n;

    vector<int> reduce(n, 0);
    string source_reduce,destination_reduce;
    pair<string,string> railway;

    for (size_t i = 0; i < n; i++){
        cout <<"Please enter the name of one source station:\n";
        getline(cin>>ws,source_reduce);
        cout <<"Please enter the name of one destination station:\n";
        getline(cin,destination_reduce);
        railway.first = source_reduce;
        railway.second = destination_reduce;
        int index = g.getIndexOfRailway(railway);
        reduce[i] = index;
    }

    g.Task4_2_2(reduce,number);
}

void Menu::Task4_2_3(){
    int number;
    cout<<"Please enter a number:\n";
    cin>>number;
    int n;
    cout <<"How many segments you want to erase ?:\n";
    cin >> n;

    vector<int> reduce(n, 0);
    string source_reduce,destination_reduce;
    pair<string,string> railway;

    for (size_t i = 0; i < n; i++){
        cout <<"Please enter the name of one source station:\n";
        getline(cin>>ws,source_reduce);
        cout <<"Please enter the name of one destination station:\n";
        getline(cin,destination_reduce);
        railway.first = source_reduce;
        railway.second = destination_reduce;
        int index = g.getIndexOfRailway(railway);
        reduce[i] = index;
    }

    g.Task4_2_3(number,reduce);
}

void Menu::main_menu() {

    while (true) {
        cout << endl;
        cout
                << "|====================================================================================================================|\n"
                   "|                                               Basic Service                                                        |\n"
                   "|====================================================================================================================|\n"
                   "| Maximum flow between 2 stations                                                                               [21] |\n"
                   "| Maximum flow between sets of stations                                                                         [22] |\n"
                   "| The railway with highest amount of trains                                                                     [23] |\n"
                   "| Pairs of stations that require the most amount of trains                                                      [24] |\n"
                   "| Top-k municipalities or districts, regarding their transportation needs in full advantage                     [25] |\n"
                   "| Top-k municipalities or districts, regarding their transportation needs in limit mode                         [26] |\n"
                   "| Number of trains that arrived in station in max flow                                                          [27] |\n"
                   "| Number of trains that arrived in station in full advantage                                                    [28] |\n"
                   "| Maximize number of trains in max flow                                                                         [29] |\n"
                   "|====================================================================================================================|\n"
                   "|                      Line Failures                        |                  Operation Cost                        |\n"
                   "|===========================================================|========================================================|\n"
                   "| Maximum flow in a reduced network segments            [41]|  Minimum cost of maintaining maximum flow         [31] |\n"
                   "| Maximum flow in a reduced network stations            [42]|                                                        |\n"
                   "| Top-k most affected stations for each segment failure [43]|                                                        |\n"
                   "|                                                       [44]|                                                        |\n"
                   "|                                                       [45]|                                                        |\n"
                   "|====================================================================================================================|\n"
                   "|                                               Other operations                                                     |\n"
                   "|====================================================================================================================|\n"
                   "|  Add stations to the network                         [11] |   Read network file                               [14] |\n"
                   "|  Add railways to the network                         [12] |   Read station file                               [15] |\n"
                   "|  Change files                                        [13] |                                                        |\n"
                   "|  Exit                                                [0]  |                                                        |\n"
                   "|====================================================================================================================|\n";

        cout << endl;
        cout << "Please choose an option:";
        int option;
        cin >> option;
        cout << endl;
        if (cin.fail() || cin.peek() != '\n') {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cerr << "Invalid input" << endl;
            continue;
        }

        switch (option) {
            case 0:
                exit(0);

            case 21:
                Task2_1();
                break;

            case 22:
                Task2_1_2();
                break;

            case 23:
                Task2_2();
                break;

            case 24:
                Task2_2_2();
                break;

            case 25:
                Task2_3();
                break;

            case 26:
                Task2_3_2();
                break;

            case 27:
                Task2_4();
                break;

            case 28:
                Task2_4_2();
                break;

            case 29:
                Task2_4_3();
                break;

            case 31:
                Task3_1();
                break;

            case 41:
                Task4_1();
                break;

            case 42:
                Task4_1_2();
                break;

            case 43:
                Task4_2();
                break;

            case 44:
                Task4_2_2();
                break;

            case 45:
                Task4_2_3();
                break;

            case 11:
                add_station();
                break;

            case 12:
                add_railway();
                break;

            case 13:
                change_file();
                break;

            case 14:
                g.printNetwork();
                break;

            case 15:
                g.printStations();
                break;

            default:
                cerr << "Invalid input" << endl;
        }
    }
}
