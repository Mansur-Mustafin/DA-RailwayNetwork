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
/**
 * Constructor of the Class Graph
 * @param input_edge_name_
 * @param input_vertex_name_
 */
Graph::Graph(const string &input_edge_name_, const string &input_vertex_name_) {
    input_edge(input_edge_name_);
    input_vertex(input_vertex_name_);
    build_adjacencyList();
    input_edge_name = input_edge_name_;
    input_vertex_name = input_vertex_name_;
}

/**
 * This function inserts a vertex (in this case a Station) into the given Graph
 * @param input_name
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

bool Graph::check_segments(const vector<int> &seg){
    for (auto i : seg){
        if (2 * i >= railways.size()){
            return false;
        }
    }
    return true;
}

bool check_Disjoint(const vector<string>& v1, const vector<string>& v2) {
    vector<string> intersection;
    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(intersection));
    return intersection.empty();
}

ostream &operator<<(ostream &out, set<int> &s){
    cout << "{";
    for (auto x : s){
        cout << x << ", ";
    }
    cout << "}";
    return out;
}

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

int Graph::Task2_1(const vector<string> &base) {
    if (!check_keys(base)) {
        return -1;
    }
    if(base[0] == base[1]) return -1;
    vector<Railway> copy_railways = railways;
    int r = ford_falk(key[base[0]], key[base[1]], copy_railways);

    for (auto &x : copy_railways) {
        if (x.getFlow() > 0 && x.getStationA() != "FROM" && x.getStationB() != "TO") {
            cout << x.getStationA() << " -> " << x.getStationB() << " " << x.getFlow() << '/'<< x.getCapacity() << endl;
        }
    }
    return r;
}

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
    for(auto el : r){
        cout << el.getStationA() << " -> " << el.getStationB()  << " (" << el.getFlow() << ")" << endl;
    }
}


void Graph::Task2_2_2() {
    vector<Railway> copy_railways = railways;
    vector<Station> copy_stations = stations;
    sort(copy_stations.begin(), copy_stations.end(), [](Station x, Station y) {return x.getNumberStations() > y.getNumberStations();});

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

    for (auto &t : trains){
        cout << t.first.first << "-" << t.first.second << ": " << t.second << endl;
    }

    while (!q.empty()){
        auto &x = q.front();

        if (x.getFlow() <= 0){
            continue;
        }
        cout << q << "\n---------------\n";
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

        cout << x << endl;
        cout << stations[key[x.getStationB()]].getDistrict() << " = "
             << result[stations[key[x.getStationB()]].getDistrict()] << endl;

        for (auto &t : trains){
            if (!t.second.empty()){
                cout << t.first.first << "-" << t.first.second
                     << ": " << t.second << endl;
            }
        }

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
        cout << ans[i].second << " " << ans[i].first << "\n";
    }
}

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

    vector<string> from;
    if(source.empty()) return -1;
    for(auto index : source){
        from.push_back(stations[index].getName());
    }

    int r = Task2_1_2(from, {station});

    return r;
}

int Graph::Task3_1(const vector<string> &base) {
    if (!check_keys(base)) {
        return -1;
    }
    vector<Railway> copy_railways = railways;
    minCostFlow(key[base[0]], key[base[1]], copy_railways);
    int result = 0;
    for (auto &copy_railway : copy_railways) {
        if (copy_railway.getFlow() > 0)
            result += (copy_railway.getFlow() * copy_railway.getCost());
    }
    return result * 2;
}

int Graph::Task4_1(const vector<string> &base, const vector<int> &reduce){
    if (!check_keys(base) || !check_segments(reduce)){
        return -1;
    }

    vector<Railway> copy_railways = railways;
    vector<Railway> copy_reduced_railways = railways;
    for (size_t i = 0; i < reduce.size(); i++){
        copy_reduced_railways[2 * reduce[i]].setCapacity(0);
        copy_reduced_railways[2 * reduce[i] + 1].setCapacity(0);
    }

    ford_falk(key[base[0]], key[base[1]], copy_railways);
    int res = ford_falk(key[base[0]], key[base[1]], copy_reduced_railways);

//    for (auto &seg : copy_railways){
//        cout << seg;
//    }
//
//    for (auto &seg : copy_reduced_railways){
//        cout << seg;
//    }

    return res;
}

int Graph::Task4_2(const vector<string> &base, const vector<int> &reduce, int k){
    if (!check_keys(base) || !check_segments(reduce)){
        return -1;
    }

    vector<Railway> copy_railways = railways;
    vector<Railway> copy_reduced_railways = railways;
    for (size_t i = 0; i < reduce.size(); i++){
        copy_reduced_railways[2 * reduce[i]].setCapacity(0);
        copy_reduced_railways[2 * reduce[i] + 1].setCapacity(0);
    }

    ford_falk(key[base[0]], key[base[1]], copy_railways);
    int res = ford_falk(key[base[0]], key[base[1]], copy_reduced_railways);

//    for (auto &seg : copy_railways){
//        cout << seg;
//    }
//
//    for (auto &seg : copy_reduced_railways){
//        cout << seg;
//    }

    vector<pair<int, int>> ans;
    for (size_t i = 0; i < copy_railways.size(); i++){
        if (copy_railways[i].getFlow() >= 0 && copy_railways[i].getFlow() != copy_reduced_railways[i].getFlow()){
            ans.push_back({-abs(copy_railways[i].getFlow() - copy_reduced_railways[i].getFlow()), (int)i});
        }
    }

    sort(ans.begin(), ans.end());

    for (size_t i = 0; i < k && i < ans.size(); i++){
        cout << copy_railways[ans[i].second] << " - "
             << copy_reduced_railways[ans[i].second] << ": " << -ans[i].first << endl;
    }

    return 0;
}

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

int Graph::getIndexOfRailway(pair<string, string> n) {
    int index = 0;
    for(auto railway : railways){
        if((n.first == railway.getStationA() && n.second == railway.getStationB()) ||
        (n.first == railway.getStationB() && n.second == railway.getStationA())) return index / 2;
        index++;
    }
    return -1;
}

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

bool Graph::check_keys(const vector<string> &base) {
    for (auto &x : base) {
        if (key.count(x) == 0) {
            return false;
        }
    }
    return true;
}

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

int Graph::Task2_4_3(const vector<string> &base) {
    // TODO
    return 0;
}
