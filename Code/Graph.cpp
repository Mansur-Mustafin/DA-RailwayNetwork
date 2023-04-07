//
// Created by musta on 15.03.2023.
//

#include "Graph.h"
#include <fstream>
#include <iostream>
#include <set>
#include <algorithm>
#include <queue>
#include <map>
#include <iomanip>

/**
 * Constructor of the Class Graph.
 * @param input_edge_name_ - Name of the file containing the names of the Railways that will be used to build the Graph
 * @param input_vertex_name_ - Name of the file containing the names of the Stations that will be used to build the Graph
 */
Graph::Graph(const string &input_edge_name_, const string &input_vertex_name_) {
    input_edge(input_edge_name_);
    input_vertex(input_vertex_name_);
    build_adjacencyList();
    input_edge_name = input_edge_name_;
    input_vertex_name = input_vertex_name_;
}

/**
 * This function inserts the Stations (in this case as vertices) in the string input_name into the given Graph.
 *
 * @complexity The time complexity of this function is O(n) where n is the number of lines of the string input_name.
 * @param input_name - Name of the file containing the vertices (or stations) we want to insert into the Graph
 */
void Graph::input_vertex(const string &input_name) {
    Station v;
    string s;
    ifstream fin(input_name);
    int ptr = 0;
    getline(fin, s);
    while (fin >> v) {
        key[v.getName()] = ptr;
        v.setInd(ptr);
        ptr++;
        stations.emplace_back(v);
    }
    fin.close();
}

/**
 * This function inserts the Railways (in this case as edges) in the string input_name into the given Graph.
 *
 * @complexity The time complexity of this function is O(n) where n is the number of lines of the string input_name.
 * @param input_name - Name of the file containing the edges (or railways) we want to insert into the Graph
 */
void Graph::input_edge(const string &input_name) {
    Railway e;
    string s;
    ifstream fin(input_name);
    getline(fin, s);
    while (fin >> e) {
        railways.emplace_back(e);
        string tmp = e.getStationA();
        e.setStationA(e.getStationB());
        e.setStationB(tmp);
        railways.emplace_back(e);
    }
    fin.close();
}

/**
 * This function inputs into the vector adjacencyList subvectors of two integers, that dictate which Stations
 * are connected to each other by analysing the vector of Railways. Each subvector has the index of Station A and
 * the index of Station B. This function also updates the number of stations for each station in the graph.
 *
 * @complexity The time complexity of this function is O(V + E) where V is the number of vertices (or stations) and
 * E is the number of edges (or railways) of the Graph.
 */
void Graph::build_adjacencyList() {
    adjacencyList.resize(stations.size());
    for (int i = 0; i < railways.size(); i += 2) {
        Railway &obj = railways[i];
        obj.setPrevPosition(i + 1);
        railways[i + 1].setPrevPosition(i);
        adjacencyList[key[obj.getStationA()]].emplace_back(i);
        adjacencyList[key[obj.getStationB()]].emplace_back(i + 1);
        stations[key[obj.getStationA()]].addNumberStations(obj.getCapacity());
        stations[key[obj.getStationB()]].addNumberStations(obj.getCapacity());
    }
}

/**
 * This function adds the Station of attributes given by the parameters to the vector stations.
 * If the boolean parameter f is true, then it will write the attributes of the Station into an output stream,
 * that can be used to write them into a file.
 *
 * @complexity The complexity of this function is O(1).
 * @param name - Name of the station we want to add
 * @param f - Boolean variable to determine if the station should be written into a file
 * @param district - District of the station we want to add
 * @param municipality - Municipality of the station we want to add
 * @param township - Township of the station we want to add
 * @param line - Line of the station we want to add
 */
void Graph::add_station(const string& name, bool f, const string& district, const string& municipality, const string& township, const string& line) {
    Station v (name, district, municipality, township, line);
    int ptr = (--stations.end())->getInd();
    v.setInd( ptr + 1);
    key[v.getName()] = ptr + 1;
    stations.emplace_back(v);
    if(f){
        ofstream out;
        out.open(input_vertex_name, ios_base::app);
        out << name << ',' << district << ',' << municipality << ',' << township << ',' << line << endl;
    }
    adjacencyList.push_back({});
}

/**
 * This function adds the Railway of attributes given by the parameters to the vector railways. After the railway is
 * added into the vector in both directions (Station A to Station B and vice versa), it will alter the adjacency list,
 * taking into account the new railways that were added.
 * If the boolean parameter f is true, then it will write the attributes of the Railway into an output stream,
 * that can be used to write them into a file.
 *
 * @complexity The complexity of this function is O(1).
 * @param nameA - Name of station A of the railway we want to add
 * @param nameB - Name of station B of the railway we want to add
 * @param f - Boolean variable to determine if the railway should be written into a file
 * @param capacity - Capacity of the railway we want to add
 * @param service - Type of service of the railway we want to add
 */
void Graph::add_railway(const string& nameA, const string& nameB, bool f, int capacity, const string& service) {
    Railway e;
    e.setStationA(nameA);
    e.setStationB(nameB);
    e.setCapacity(capacity);
    e.setService(service);
    e.setCost((e.getService() == "STANDARD") ? 1 : 2);
    railways.emplace_back(e);
    string tmp = e.getStationA();
    e.setStationA(e.getStationB());
    e.setStationB(tmp);
    railways.emplace_back(e);
    int n = railways.size();
    railways[n - 2].setPrevPosition(n - 1);
    railways[n - 1].setPrevPosition(n - 2);
    adjacencyList[key[nameA]].emplace_back(n - 2);
    adjacencyList[key[nameB]].emplace_back(n - 1);
    if(f){
        ofstream out;
        out.open(input_edge_name, ios_base::app);
        out << nameA << ',' << nameB << ',' << capacity << ',' << service << endl;
    }
}

/**
<<<<<<< HEAD
 * This function determines whether a segment defined by a vector of integers belongs the Graph or not.
 *
 * @complexity The time complexity of this function is O(n).
 * @param seg - Vector of integers that represents a segment between stations. The integers of the vector represent
 * the stations indexes
 * @return false if the segment cannot exist in the Graph and true otherwise.
 */
bool Graph::check_segments(const vector<int> &seg){
    for (auto i : seg){
        if (2 * i >= railways.size()){
            return false;
        }
    }
    return true;
}

/**
 * This function determines whether stations are connected in the graph or, in other words, whether if it is
 * possible to reach the stations in vector v1 from the stations in vector v2 and vice versa.
 *
 * @complexity The time complexity of this function is O(1).
 * @param v1 - Vector of strings number one, with the strings being the names of Stations
 * @param v2 - Vector of strings number two, with the strings being the names of Stations
 * @return true if the stations can reach each other and false if they cannot.
 */
bool check_Disjoint(const vector<string>& v1, const vector<string>& v2) {
    vector<string> intersection;
    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(intersection));
    return intersection.empty();
}

/**
=======
>>>>>>> 617219e24c649cd9da7795e7e71bce49c02a524f
 * This operator specifies how a set of integers should be written into an output stream.
 *
 * @complexity The time complexity of this operator is O(n) where n is the number of elements of the set s.
 * @param out - Output stream where the set of integers will be written into
 * @param s - Set of integers
 * @return output stream with the integers contained in the parameter s.
 */
ostream &operator<<(ostream &out, set<int> &s){
    cout << "{";
    for (auto x : s){
        cout << x << ", ";
    }
    cout << "}";
    return out;
}

/**
 * This operator specifies how a queue of objects of the class Railway should be written into an output stream.
 *
 * @complexity The time complexity of this operator is O(n) where n is the number of elements of the queue s.
 * @param out - Output stream where the queue of Railways will be written into
 * @param s - Queue of Railways
 * @return output stream with the Railways contained in the parameter s.
 */
ostream &operator<<(ostream &out, queue<Railway> &s){
    cout << "{";
    queue<Railway> t = s;
    while (!t.empty()){
        cout << t.front() << ", ";
        t.pop();
    }
    cout << "}";
    return out;
}

/**
 * This function determines the maximum flow between two stations.
 * @param base - vector of two strings with each one being the name of one of the stations we are analysing
 * @return an integer with the maximum flow between two stations.
 */
int Graph::Task2_1(const vector<string> &base) {
    if (!check_keys(base)) {
        return -1;
    }
    if(base[0] == base[1]) return -1;
    vector<Railway> copy_railways = railways;
    int r = ford_falk(key[base[0]], key[base[1]], copy_railways);

    cout << r << endl;

    for (auto &x : copy_railways) {
        if (x.getFlow() > 0 && x.getStationA() != "FROM" && x.getStationB() != "TO") {
            cout << x.getStationA() << " -> " << x.getStationB() << " " << x.getFlow() << '/'<< x.getCapacity() << endl;
        }
    }

    return r;
}

/**
 * This function determines the maximum flow between a group of "source" Stations and "sink" Stations.
 * @param from - vector of strings with each string being the name of one "source" Stations
 * @param to - vector of strings with each string being the name of one "sink" Stations
 * @return an integer with the maximum flow between two stations.
 */
int Graph::Task2_1_2(const vector<string> &from, const vector<string> &to) {
    if(!check_keys(from) || !check_keys(to)){
        return -1;
    }
    if(!check_Disjoint(from, to)){
        return -1;
    }
    add_station("FROM", false);
    add_station("TO", false);
    for(const auto& station : from){
        add_railway("FROM", station, false);
    }
    for(const auto& station : to){
        add_railway(station, "TO", false);
    }

    vector<string> base = {"FROM", "TO"};
    int r =  Task2_1(base);

    for(const auto& station : from){
        adjacencyList[key[station]].pop_back();
    }
    for(const auto& station : to){
        adjacencyList[key[station]].pop_back();
    }
    adjacencyList.pop_back();
    adjacencyList.pop_back();
    stations.pop_back();
    stations.pop_back();
    return r;
}

/**
 *
 * @param base
 * @return
 */
int Graph::Task2_1_3(const vector<string> &base) {
    if (!check_keys(base)) {
        return -1;
    }
    if(base[0] == base[1]) return -1;
    vector<Railway> copy_railways = railways;

    int r = edmonds_karp(key[base[0]], key[base[1]], copy_railways);

    for (auto &x : copy_railways) {
        if (x.getFlow() > 0 && x.getStationA() != "FROM" && x.getStationB() != "TO") {
            cout << x.getStationA() << " -> " << x.getStationB() << " " << x.getFlow() << '/'<< x.getCapacity() << endl;
        }
    }
    return r;
}

/**
 * This function prints the stations whose railway has the highest flow and the respective flow between them.
 * @param base
 */
void Graph::Task2_2(vector<string> &base) {
    if (!check_keys(base)) {
        return;
    }
    vector<Railway> copy_railways = railways;
    ford_falk(key[base[0]], key[base[1]], copy_railways);

    vector<Railway> r;
    int mx = -1;

    for (const auto &x : copy_railways) {
        if (x.getFlow() > mx) {
            mx = x.getFlow();
            r.clear();
            r.push_back(x);
        }else if(x.getFlow() == mx){
            r.push_back(x);
        }
    }
    for(const auto& el : r){
        cout << el.getStationA() << " -> " << el.getStationB()  << " (" << el.getFlow() << ")" << endl;
    }
}

/**
 * This function prints the pairs of stations whose railways have the maximum flow.
 */
void Graph::Task2_2_2() {
    vector<Railway> copy_railways = railways;
    vector<Station> copy_stations = stations;
    sort(copy_stations.begin(), copy_stations.end(), [](const Station& x, const Station& y) {return x.getNumberStations() > y.getNumberStations();});

    struct answer{
        string s1;
        string s2;
        int flow;
    };

    vector<answer> r;
    int cur, max = -1;

    for(int i = 0; i < copy_stations.size(); i++){
        if(max > copy_stations[i].getNumberStations()){
            break;
        }
        for(int j = 0; j < i; j++){
            cur = ford_falk(key[copy_stations[i].getName()], key[copy_stations[j].getName()], copy_railways);
            copy_railways = railways;
            //cout << copy_stations[i].name << " " <<  copy_stations[j].name << "  " << cur << endl;
            if(cur > max){
                max = cur;
                r.clear();
                answer a = {copy_stations[i].getName(),copy_stations[j].getName(), cur};
                r.push_back(a);
            }else if(cur == max){
                answer a = {copy_stations[i].getName(),copy_stations[j].getName(), cur};
                r.push_back(a);
            }
        }
    }
    for(auto e : r){
        cout << e.s1 << " -> " << e.s2 << " (" << e.flow << ")" << endl;
    }
}

/**
 * This function prints which municipalities and districts need more budget for purchasing and maintaining more trains,
 * according to the overall capacity of the stations and railways included in each municipality and/or district.
 * @param base
 * @param k
 * @param flag
 */
void Graph::Task2_3(vector<string> &base, int k, bool flag) {
    if (!check_keys(base)) {
        return;
    }
    // TODO k and flag
    vector<Railway> copy_railways = railways;
    int tmp = ford_falk(key[base[0]], key[base[1]], copy_railways);
    unordered_map<string, int> result;

    if(flag){
        result[stations[key[base[0]]].getMunicipality()] += tmp;
    }else{
        result[stations[key[base[0]]].getDistrict()] += tmp;
    }

    for (auto &x : copy_railways) {
        if (x.getFlow() <= 0) {
            continue;
        }
        if (flag) {
            if (stations[key[x.getStationA()]].getMunicipality() != stations[key[x.getStationB()]].getMunicipality()
                && stations[key[x.getStationB()]].getMunicipality() != stations[key[base[0]]].getMunicipality()) {
                result[stations[key[x.getStationB()]].getMunicipality()] += x.getFlow();
            }
        }else if (stations[key[x.getStationA()]].getDistrict() != stations[key[x.getStationB()]].getDistrict()
                && stations[key[x.getStationB()]].getDistrict() != stations[key[base[0]]].getDistrict()) {
            result[stations[key[x.getStationB()]].getDistrict()] += x.getFlow();
        }
    }
    vector<pair<int, string>> ans;
    for (auto &x : result) {
        ans.emplace_back(x.second, x.first);
    }
    sort(ans.rbegin(), ans.rend());
    for (int i = 0; i < ans.size() && i < k; i++) {
        cout << ans[i].second << " " << ans[i].first << "\n";
    }
}

/**
 * This function prints which municipalities and districts need more budget for purchasing and maintaining more trains,
 * according to the overall capacity of the stations and railways included in each municipality and/or district, but
 * also taking into account that the network has a limited number of trains, given by the total flow of all the railways
 * in the network.
 * @param base
 * @param k
 * @param flag
 */
void Graph::Task2_3_2(vector<string> &base, int k, bool flag){
    if (!check_keys(base)){
        return;
    }
    // TODO k and flag
    vector<Railway> copy_railways = railways;
    ford_falk(key[base[0]], key[base[1]], copy_railways);
    unordered_map<string, set<int>> result;
    map<std::pair<string, string>, set<int>> trains;
    queue<Railway> q;

    int train_id = 1;
    for (auto &x : copy_railways){
        if (x.getStationA() == base[0] && x.getFlow() > 0){
            q.push(x);
            for (size_t i = 0; i < x.getFlow(); i++){
                trains[{x.getStationA(), x.getStationB()}].insert(train_id);
                train_id++;
            }
        }
    }

//    for (auto &t : trains){
//        cout << t.first.first << "-" << t.first.second << ": " << t.second << endl;
//    }

    while (!q.empty()){
        auto &x = q.front();

        if (x.getFlow() <= 0){
            continue;
        }
        //cout << q << "\n---------------\n";
        q.pop();

        set<int> &local_trains = trains[{x.getStationA(), x.getStationB()}];
        if (flag){
            if (stations[key[x.getStationA()]].getMunicipality() !=
                stations[key[x.getStationB()]].getMunicipality()){
                for (auto train_id : trains[{x.getStationA(), x.getStationB()}]){
                    result[stations[key[x.getStationB()]].getMunicipality()].insert(train_id);
                }
            }
        }
        else if (stations[key[x.getStationA()]].getDistrict() !=
                 stations[key[x.getStationB()]].getDistrict()){
            for (auto train_id : trains[{x.getStationA(), x.getStationB()}]){
                result[stations[key[x.getStationB()]].getDistrict()].insert(train_id);
            }
        }

        for (auto &y : copy_railways){
            if (y.getStationA() == x.getStationB() && y.getFlow() > 0){
                for (size_t i = 0; i < y.getFlow() && !local_trains.empty(); i++){
                    int train_id = *local_trains.begin();
                    trains[{y.getStationA(), y.getStationB()}].insert(train_id);
                    local_trains.erase(local_trains.begin());
                }
            }
        }

//        cout << x << endl;
//        cout << stations[key[x.getStationB()]].getDistrict() << " = "
//             << result[stations[key[x.getStationB()]].getDistrict()] << endl;

//        for (auto &t : trains){
//            if (!t.second.empty()){
//                cout << t.first.first << "-" << t.first.second
//                     << ": " << t.second << endl;
//            }
//        }

        for (auto v : adjacencyList[key[x.getStationB()]]){
            if (copy_railways[v].getFlow()> 0){
                q.push(copy_railways[v]);
            }
        }
    }
    vector<pair<int, string>> ans;
    for (auto &x : result){
        ans.emplace_back(x.second.size(), x.first);
    }
    sort(ans.rbegin(), ans.rend());
    for (int i = 0; i < ans.size() && i < k; i++){
        cout << "The district: " << ans[i].second << " needs: " << ans[i].first << " trains" "\n";
    }
}

/**
 * This function prints the number of trains that get into a Station when there is maximum flow.
 * @param base
 */
void Graph::Task2_4(const vector<string> &base) {
    if (key.count(base[2]) == 0) {
        cout << -1;
        return;
    }
    vector<Railway> copy_railways = railways;
    ford_falk(key[base[0]], key[base[1]], copy_railways);
    int count = 0;
    int pos = key[base[2]];
    for (int i : adjacencyList[pos]) {
        if (copy_railways[i].getFlow() < 0) {
            count += (-copy_railways[i].getFlow());
        }
    }
    cout << count << "\n";
}

/**
 * This function determines the number of trains that can get into a Station.
 * @param station
 * @return an integer with the number of trains that can get into a Station.
 */
int Graph::Task2_4_2(const string &station) {

    if (key.count(station) == 0) {
        return -1;
    }

    vector<int> source;
    for(int i = 0; i < adjacencyList.size(); i++){
        if(adjacencyList[i].size() == 1){
            source.push_back(i);
        }
    }

    if(source.empty()){
        cout << "Not sours stations. Result: " << stations[key[station]].getNumberStations();
        return stations[key[station]].getNumberStations();
    }

    vector<string> from;
    if(source.empty()) return -1;
    for(auto index : source){
        from.push_back(stations[index].getName());
    }

    int r = Task2_1_2(from, {station});

    return r;
}

/**
 * This function returns the maximum number of trains that can get into a station when there is maximum flow.
 * @param base
 * @return an integer with value equal to the number of trains that can get into a station when there is maximum flow.
 */
int Graph::Task2_4_3(const vector<string> &base) {
    cout << "From " << base[0] << " to " << base[1] << " maximize the " << base[2] << endl;
    if (!check_keys(base)) {
        return -1;
    }
    if(base[0] == base[1]) return -1;
    if(base[1] == base[2]) return Task2_1({base[0], base[1]});
    vector<Railway> copy_railways = railways;

    int r = edmonds_karp_priority(key[base[0]], key[base[1]], key[base[2]], copy_railways);

    int in = 0;

    for (auto &x : copy_railways) {
        if (x.getFlow() > 0 && x.getStationA() != "FROM" && x.getStationB() != "TO") {
            cout << x.getStationA() << " -> " << x.getStationB() << " " << x.getFlow() << '/'<< x.getCapacity() << endl;
            if(x.getStationB() == base[2]){
                in += x.getFlow();
            }
        }
    }

    cout << "Max Flow: " << r << endl;
    cout << "Result of maximize: " << in << endl;
    return r;
}

/**
 * This function determines the maximum amount of trains that can simultaneously travel between two specific stations
 * with minimum cost.
 * @param base
 * @return an integer with the maximum number of trains that can travel simultaneously between two stations.
 */
int Graph::Task3_1(const vector<string> &base) {
    if (!check_keys(base)) {
        return -1;
    }
    int flow = 0;
    vector<Railway> copy_railways = railways;
    minCostFlow(key[base[0]], key[base[1]], copy_railways);
    int result = 0;
    for (auto &copy_railway : copy_railways) {
        if (copy_railway.getFlow() > 0){
            result += (copy_railway.getFlow() * copy_railway.getCost());
            if(copy_railway.getStationB() == base[1]){
                flow += copy_railway.getFlow();
            }
        }
    }
    for(auto it = copy_railways.rbegin(); it != copy_railways.rend(); it++){
        if(it->getFlow() > 0){
            cout << (*it);
        }
    }
//    int c = 0;
//    for (auto &copy_railway : copy_railways) {
//        if (copy_railway.getFlow() > 0){
//            cout << copy_railway;
//            cout << copy_railway.getCost() * 2 << " * " << copy_railway.getFlow() << " = " <<  copy_railway.getCost() * 2 * copy_railway.getFlow() << " (for now r:" << c + copy_railway.getCost() * 2 * copy_railway.getFlow() << ")" << endl;
//            c += copy_railway.getCost() * 2 * copy_railway.getFlow();
//            cout << endl;
//        }
//    }
//    cout << "result : " << c << endl;
    cout << endl << "Total Cost: " << result * 2 << endl;
    cout << "Total Flow: " << flow << endl;
    return result * 2;
}

/**
 * This function determines the maximum number of trains that can travel in a specific railway of a reduced Graph.
 * @param base
 * @param reduce
 * @return an integer with the maximum number of trains that can travel simultaneously between in a railway
 * of a subgraph (or reduced Graph).
 */
int Graph::Task4_1(const vector<string> &base, const vector<int> &reduce){
    if (!check_keys(base) || !check_segments(reduce)){
        return -1;
    }

    vector<Railway> copy_railways = railways;
    vector<Railway> copy_reduced_railways = railways;
    for (int i : reduce){
        copy_reduced_railways[2 * i].setCapacity(0);
        copy_reduced_railways[2 * i + 1].setCapacity(0);
    }

    int res = ford_falk(key[base[0]], key[base[1]], copy_reduced_railways);

//    for (auto &seg : copy_railways){
//        cout << seg;
//    }
//
//    for (auto &seg : copy_reduced_railways){
//        cout << seg;
//    }

    for (auto &copy_railway : copy_reduced_railways) {
        if (copy_railway.getFlow() > 0)
            cout << copy_railway;
    }
    cout << "Max flow: " << res << endl;
    return res;
}

/**
 * This function determines the maximum number of trains that can travel between two
 * specific stations of a reduced Graph.
 * @param base
 * @param name_of_stations
 * @return an integer with the maximum number of trains that can travel simultaneously between two specific stations
 * of a subgraph (or reduced Graph).
 */
int Graph::Task4_1_2(const vector<string> &base, const vector<string> &name_of_stations) {
    vector<int> reduce;
    int res = 0;

    for(const auto& name: name_of_stations){
        int index = key[name];
        vector<int> v = adjacencyList[index];
        for(auto i : v){
            reduce.push_back(i / 2);
        }
    }

    res = Task4_1(base, reduce);

    return res;
}

/**
 * This function prints the stations that would have a more significant loss of flow (or traffic of trains) when each
 * segment of the network is deemed to be nonoperational.
 * @param base
 * @param reduce
 * @param k
 * @param f
 * @return
 */
int Graph::Task4_2(const vector<string> &base, const vector<int> &reduce, int k, bool f){
    if (!check_keys(base) || !check_segments(reduce)){
        return -1;
    }

    vector<Railway> copy_railways = railways;
    vector<Railway> copy_reduced_railways = railways;
    for (int i : reduce){
        copy_reduced_railways[2 * i].setCapacity(0);
        copy_reduced_railways[2 * i + 1].setCapacity(0);
    }

    int old = ford_falk(key[base[0]], key[base[1]], copy_railways);
    int res = ford_falk(key[base[0]], key[base[1]], copy_reduced_railways);

//    for (auto &seg : copy_railways){
//        cout << seg;
//    }

    if(f){
        cout << endl << "Residual flow: " << endl << endl;
        for (auto &seg : copy_reduced_railways){
            if(seg.getFlow() > 0){
                cout << seg;
            }
        }
    }

    cout << endl << "Old Max Flow: " << old << endl;
    cout << "New Max Flow: " << res << endl;

    vector<pair<int, int>> ans;
    for (size_t i = 0; i < copy_railways.size(); i++){
        if (copy_railways[i].getFlow() >= 0 && copy_railways[i].getFlow() != copy_reduced_railways[i].getFlow()){
            ans.push_back({-abs(copy_railways[i].getFlow() - copy_reduced_railways[i].getFlow()), (int)i});
        }
    }

    sort(ans.begin(), ans.end());

    if(ans.empty()){
        cout << "Nothing was changed";
        return 0;
    }

//    for (size_t i = 0; i < k && i < ans.size(); i++){
//        cout << copy_railways[ans[i].second] << " - "
//             << copy_reduced_railways[ans[i].second] << ": " << -ans[i].first << endl;
//    }


    cout << endl << "Decreased flow: " << endl;
    for (size_t i = 0; i < k && i < ans.size(); i++){
        if(copy_railways[ans[i].second].getFlow() > copy_reduced_railways[ans[i].second].getFlow()){
            cout << copy_railways[ans[i].second].getStationA() << " -> " << copy_railways[ans[i].second].getStationB()
                 << " : " << -ans[i].first << endl;
        }
    }

    cout << endl << "Increased flow: " << endl;
    for (size_t i = 0; i < k && i < ans.size(); i++){
        if(copy_railways[ans[i].second].getFlow() < copy_reduced_railways[ans[i].second].getFlow()){
            cout << copy_railways[ans[i].second].getStationA() << " -> " << copy_railways[ans[i].second].getStationB()
                 << " : " << -ans[i].first << endl;
        }
    }

    return 0;
}

/**
 * This function implements the Ford-Fulkerson algorithm on the Graph in order to find the maximum flow from a "source"
 * vertex represented by parameter s to a "sink" vertex represented by parameter t.
 *
 * @complexity The time complexity of this function is O(F * E) where F is the maximum flow and E is the number
 * of edges of the Graph.
 * @param s - Integer representing the index of the "Source" Station
 * @param t - Integer representing the index of the "Sink" Station
 * @param rail - Vector of Objects of the class Railway
 * @param skip -
 * @return an integer with the value of the maximum flow between the "source" vertex and the "sink" vertex.
 */
int Graph::ford_falk(int s, int t, vector<Railway> &rail, int skip) {
    int result = 0;
    while (true) {
        vector<bool> mark(adjacencyList.size(), false);
        if (skip != -1) {
            mark[skip] = true;
        }
        int x = dfs(s, t, 1e9, mark, rail);
        if (x == 0) {
            break;
        }
        result += x;
    }
    return result;
}

/**
 * This function implements the Depth First Search algorithm on the Graph in order to find the maximum flow that can be
 * added between two vertices of the Graph.
 *
 * @complexity The time complexity of this function is O(E) where E represents the number of edges of the Graph.
 * @param v - Integer representing the index of the starting vertex
 * @param t - Integer representing the index of the target vertex
 * @param current_min - Integer representing the current minimum flow of the search
 * @param mark - Vector of boolean variables, where the index of each variable is the index of a vertex. If the variable
 * is true then it means the vertex with its index has been visited already.
 * @param rail - Vector of objects of the class Railway
 * @return 0 if the vertex v has been visited before, current_min if the vertex v is equal to vertex t and the maximum
 * flow that can be added otherwise.
 */
int Graph::dfs(int v, int t, int current_min, vector<bool> &mark, vector<Railway> &rail) {
    if (mark[v]) {
        return 0;
    }
    mark[v] = true;
    if (v == t) {
        int p;
        return current_min;
    }
    for (int q : adjacencyList[v]) {
        if (rail[q].getFlow() < rail[q].getCapacity()) {
            int mn =
                    dfs(key[rail[q].getStationB()], t,
                        min(current_min, rail[q].getCapacity() - rail[q].getFlow()), mark, rail);
            if (mn > 0) {
                rail[q].addFlow(mn);
                rail[rail[q].getPrevPosition()].subFlow(mn);
                return mn;
            }
        }
    }
    return 0;
}

/**
 * This functions implements the Edmonds-Karp algorithm to determine the maximum flow in the Graph with a "source"
 * vertex given by s and a "target" vertex given by t.
 *
 * @complexity The time complexity of this function is O(V * E^2) where V is the number of vertices and E is the
 * number of edges of the Graph.
 * @param s - Integer representing the index of the "source" vertex
 * @param t - Integer representing the index of the "target" vertex
 * @param rail - Vector of objects of the class Railway
 * @return an integer with the maximum flow from s to t
 */
int Graph::edmonds_karp(int s, int t,  vector<Railway> &rail) {
    int result = 0;
    while(true){
        vector<int> mark(adjacencyList.size(), -1);
        int x = bfs(s, t, -1, rail, mark);
        if(x == 0) break;
        result += x;
        int cur = t;
        while (cur != s) {
            int prev = mark[cur];
            int r = 0;
            for(auto i : adjacencyList[prev]){
                if(rail[i].getStationB() == stations[cur].getName()){
                    r = i;
                }
            }
            rail[r].addFlow(x);
            rail[rail[r].getPrevPosition()].subFlow(x);
            cur = prev;
        }
    }
    return result;
}

/**
 * This function implements the Breadth First Search Algorithm to determine an augmenting path and the maximum flow that
 * can be "pushed" into this path between a "source" vertex and a "target" vertex.
 *
 * @complexity The time complexity of this function is O(E) where E is the number of edges of the Graph.
 * @param s - Integer representing the index of the "source" vertex
 * @param t - Integer representing the index of the "target" vertex
 * @param u -
 * @param rail - Vector of objects of the class Railway
 * @param mark -
 * @return 0 if no path can be found between the source vertex and the target vertex and the maximum flow that can exists
 * in the path between the vertices.
 */
int Graph::bfs(int s, int t, int u, vector<Railway> &rail, vector<int>& mark) {
    mark.assign(adjacencyList.size(), -1);
    mark[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, 1e9});

    while (!q.empty()) {
        int u = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int v : adjacencyList[u]) {
            if(rail[v].getFlow() < rail[v].getCapacity() ){
                int index_to_go = key[rail[v].getStationB()];
                if(mark[index_to_go] == -1){
                    mark[index_to_go] = u;
                    int new_flow = min(flow, rail[v].getCapacity() - rail[v].getFlow());
                    if(index_to_go == t){
                        return new_flow;
                    }
                    q.push({index_to_go, new_flow});
                }
            }
        }
    }
    return 0;
}

/**
 * This function applies the Dijkstra's algorithm in order to find the shortest path from "source" vertex s to
 * "sink" vertex t that has positive capacity and adds the maximum flow possible along the path it chooses while
 * minimizing the cost.
 *
 * The time complexity of this function is O(E * V^2) where E is the number of edges and V is the number of vertices.
 * @param s
 * @param t
 * @param rail
 */
void Graph::minCostFlow(int s, int t, vector<Railway> &rail) {
    while (true) {
        pair<int, vector<int>> res = dijkstra(s, t, rail);
        if (res.first <= 0) {
            break;
        }
        for (int x : res.second) {
            Railway e = rail[x];
            rail[x].addFlow(res.first);
            rail[e.getPrevPosition()].subFlow(res.first);
        }
    }
}

/**
 * This function implements the Dijkstra algorithm in order to find the shortest path between two vertices in a
 * Graph.
 *
 * @complexity The time complexity of this function is O((V+E) * log V) where V represents the number of vertices and E
 * represents the number of edges of the Graph.
 * @param s - Integer representing the index of the starting vertex
 * @param t - Integer representing the index of the target vertex
 * @param rail - Vector of objects of the class Railway
 * @return a pair of values: the minimum capacity along the path and a vector of edges representing the path.
 */
pair<int, vector<int>> Graph::dijkstra(int s, int t, vector<Railway> &rail) {
    set<pair<int, int>> q;
    vector<int> d(adjacencyList.size(), 1e9);
    vector<pair<int, int>> parent(adjacencyList.size());
    d[s] = 0;
    parent[s] = make_pair(-1, -1);
    q.insert(make_pair(0, s));
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        for (int ptr : adjacencyList[v]) {
            const Railway &e = rail[ptr];
            int to = key[e.getStationB()];
            int len = e.getCost();
            if (d[v] + len < d[to] && e.getFlow() < e.getCapacity()) {
                q.erase(make_pair(d[to], to));
                d[to] = d[v] + len;
                q.insert(make_pair(d[to], to));
                parent[to] = make_pair(v, ptr);
            }
        }
    }
    if (d[t] == 1e9) {
        return make_pair(0, vector<int>());
    }
    vector<int> edgesPath;
    pair<int, int> v = parent[t];
    while (v.first != -1) {
        edgesPath.push_back(v.second);
        v = parent[v.first];
    }
    reverse(edgesPath.begin(), edgesPath.end());
    int minCapacity = 1e9;
    for (int it : edgesPath) {
        minCapacity = min(minCapacity, rail[it].getCapacity() - rail[it].getFlow());
    }
    return make_pair(minCapacity, edgesPath);
}

/**
 * This function determines whether a vector containing the names of stations contains a name of a station that
 * does not belong to the unordered map key and therefore is not a valid name of a Station in the Graph.
 *
 * @complexity The time complexity of this function is O(n) where n is the number of elements of the vector base.
 * @param base - vector of strings, each being a name of a Station
 * @return true if all the names in the parameter base exist in the unordered map key of the Graph and false if at least
 * one of the names does not.
 */
bool Graph::check_keys(const vector<string> &base) {
    for (auto &x : base) {
        if (key.count(x) == 0) {
            return false;
        }
    }
    return true;
}

int Graph::edmonds_karp_priority(int s, int t, int u, vector<Railway> &rail) {
    int result = 0;
    while(true){
        vector<int> mark(adjacencyList.size(), -1);

        int xp = bfs_priority(s, t, u, rail, mark);

        if(xp == 0){
            int x = bfs(s, t, u, rail, mark);
            if(x == 0) break;
            result += x;
            int cur = t;
            while (cur != s) {
                int prev = mark[cur];
                int r = 0;
                for(auto i : adjacencyList[prev]){
                    if(rail[i].getStationB() == stations[cur].getName()){
                        r = i;
                    }
                }
                rail[r].addFlow(x);
                rail[rail[r].getPrevPosition()].subFlow(x);
                cur = prev;
            }
        }else{
            result += xp;
            int cur = t;
            while (cur != s) {
                int prev = mark[cur];
                int r = 0;
                for(auto i : adjacencyList[prev]){
                    if(rail[i].getStationB() == stations[cur].getName()){
                        r = i;
                    }
                }
                rail[r].addFlow(xp);
                rail[rail[r].getPrevPosition()].subFlow(xp);
                cur = prev;
            }
        }

    }
    return result;
}

int Graph::bfs_priority(int s, int t, int u, vector<Railway> &rail, vector<int>& mark) {
    mark.assign(adjacencyList.size(), -1);
    mark[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, 1e9});
    int first_flow = 0;
    while (!q.empty()) {
        int w = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int v : adjacencyList[w]) {
            if(rail[v].getFlow() < rail[v].getCapacity() ){
                int index_to_go = key[rail[v].getStationB()];
                if(mark[index_to_go] == -1 && index_to_go != t){
                    mark[index_to_go] = w;
                    int new_flow = min(flow, rail[v].getCapacity() - rail[v].getFlow());
                    if(index_to_go == u){
                        first_flow = new_flow;
                    }
                    q.push({index_to_go, new_flow});
                }
            }
        }
    }
    if(first_flow == 0) return 0;

    q.push({u, first_flow});

    while (!q.empty()) {
        int w = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int v : adjacencyList[w]) {
            if(rail[v].getFlow() < rail[v].getCapacity() ){
                int index_to_go = key[rail[v].getStationB()];
                if(mark[index_to_go] == -1 && index_to_go != u){
                    mark[index_to_go] = w;
                    int new_flow = min(flow, rail[v].getCapacity() - rail[v].getFlow());
                    if(index_to_go == t){
                        return new_flow;
                    }
                    q.push({index_to_go, new_flow});
                }
            }
        }
    }

    return 0;
}

/**
 * This function obtains the index of the Railway whose Stations' names are contained in the parameter n.
 *
 * The time complexity of this function is O(n).
 * @param n
 * @return an integer with value equal to the index of the pretended Railway, or -1 if the pretended Railway
 * is not found in the vector railways of the Graph.
 */
int Graph::getIndexOfRailway(const pair<string, string>& n) {
    int index = 0;
    for(const auto& railway : railways){
        if((n.first == railway.getStationA() && n.second == railway.getStationB()) ||
           (n.first == railway.getStationB() && n.second == railway.getStationA())) return index / 2;
        index++;
    }
    return -1;
}

/**
 * This function determines whether stations are connected in the graph or, in other words, whether if it is
 * possible to reach the stations in vector v1 from the stations in vector v2 and vice versa.
 *
 * The time complexity of this function is O(1).
 * @param v1
 * @param v2
 * @return true if the stations can reach each other and false if they cannot.
 */
bool Graph::check_Disjoint(const vector<string>& v1, const vector<string>& v2) {
    vector<string> intersection;
    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(intersection));
    return intersection.empty();
}

/**
 * This function writes an "image" contained in a text document into the terminal.
 *
 * @complexity The time complexity of this function is O(n) where n is the number of lines of the text file.
 */
void Graph::printImage(const string& name, bool f) {
    if(f) cout << "File name: " << name << endl;
    ifstream file(name);
    string line;
    cout << endl;
    while (std::getline(file, line)) {
        std::cout << line << '\n';
    }
    cout << endl << endl;
}

string Graph::getStationName() {
    return input_vertex_name;
}

string Graph::getNetworkName() {
    return input_edge_name;
}

void Graph::printNetwork() {
    cout << "File name: " << input_edge_name << endl;
    int i = 0;
    for(const auto& n : railways){
        cout << '[' << i++ << "]  " << n;
    }
}

void Graph::printStations() {
    cout << "File name: " << input_vertex_name << endl;
    vector<string> v = {"Name" , "District" , "Municipality", "Township", "Line" };
    for(auto el : v ) cout << left << setw(40) << el;
    cout << endl;
    for(int i = 0; i < 200; i++) cout << '-';
    cout << endl;
    for(const auto& n : stations){
        cout << n;
    }
}
