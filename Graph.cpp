//
// Created by musta on 15.03.2023.
//

#include "Graph.h"
#include <fstream>
#include <iostream>
#include <set>
#include <algorithm>

Graph::Graph(const string &input_edge_name, const string &input_vertex_name) {
    input_edge(input_edge_name);
    input_vertex(input_vertex_name);
    build_adjacencyList();
}

void Graph::input_vertex(const string &input_name) {
    Station v;
    string s;
    ifstream fin(input_name);
    int ptr = 0;
    getline(fin, s);
    while (fin >> v) {
        key[v.getName()] = ptr;
        v.setInd(ptr++);
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
        swap(e.station_A, e.station_B);
        railways.emplace_back(e);
    }
    fin.close();
}

void Graph::build_adjacencyList() {
    adjacencyList.resize(stations.size());
    for (int i = 0; i < railways.size(); i += 2) {
        Railway &obj = railways[i];
        obj.prev_position = i + 1;
        railways[i + 1].prev_position = i;
        adjacencyList[key[obj.station_A]].emplace_back(i);
        adjacencyList[key[obj.station_B]].emplace_back(i + 1);
        stations[key[obj.station_A]].addNumberStations(obj.capacity);
        stations[key[obj.station_B]].addNumberStations(obj.capacity);
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

int Graph::Task2_1(const vector<string> &base) {
    if (!check_keys(base)) {
        return -1;
    }
    vector<Railway> copy_railways = railways;
    int r = ford_falk(key[base[0]], key[base[1]], copy_railways);

    for (auto &x : copy_railways) {
        if (x.flow > 0) {
            cout << x.station_A << " -> " << x.station_B << " " << x.flow << '/'<< x.capacity << endl;
        }
    }
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
        if (x.flow > mx) {
            mx = x.flow;
            r.clear();
            r.push_back(x);
        }else if(x.flow == mx){
            r.push_back(x);
        }
    }
    for(auto el : r){
        cout << el.station_A << " -> " << el.station_B  << " (" << el.flow << ")" << endl;
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
        if (x.flow <= 0) {
            continue;
        }
        if (flag) {
            if (stations[key[x.station_A]].getMunicipality() != stations[key[x.station_B]].getMunicipality()
                && stations[key[x.station_B]].getMunicipality() != stations[key[base[0]]].getMunicipality()) {
                result[stations[key[x.station_B]].getMunicipality()] += x.flow;
            }
        }else if (stations[key[x.station_A]].getDistrict() != stations[key[x.station_B]].getDistrict()
                && stations[key[x.station_B]].getDistrict() != stations[key[base[0]]].getDistrict()) {
            result[stations[key[x.station_B]].getDistrict()] += x.flow;
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
        if (copy_railways[i].flow < 0) {
            count += (-copy_railways[i].flow);
        }
    }
    cout << count << "\n";
}

int Graph::Task3_1(const vector<string> &base) {
    if (!check_keys(base)) {
        return -1;
    }
    vector<Railway> copy_railways = railways;
    minCostFlow(key[base[0]], key[base[1]], copy_railways);
    int result = 0;
    for (auto &copy_railway : copy_railways) {
        if (copy_railway.flow > 0)
            result += (copy_railway.flow * copy_railway.cost);
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
        copy_reduced_railways[2 * reduce[i]].capacity = 0;
        copy_reduced_railways[2 * reduce[i] + 1].capacity = 0;
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
        copy_reduced_railways[2 * reduce[i]].capacity = 0;
        copy_reduced_railways[2 * reduce[i] + 1].capacity = 0;
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
        if (copy_railways[i].flow >= 0 && copy_railways[i].flow != copy_reduced_railways[i].flow){
            ans.push_back({-abs(copy_railways[i].flow - copy_reduced_railways[i].flow), (int)i});
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
        if (rail[q].flow < rail[q].capacity) {
            int mn =
                    dfs(key[rail[q].station_B], t,
                        min(current_min, rail[q].capacity - rail[q].flow), mark, rail);
            if (mn > 0) {
                rail[q].flow += mn;
                rail[rail[q].prev_position].flow -= mn;
                return mn;
            }
        }
    }
    return 0;
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
            int to = key[e.station_B];
            int len = e.cost;
            if (d[v] + len < d[to] && e.flow < e.capacity) {
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
        minCapacity = min(minCapacity, rail[it].capacity - rail[it].flow);
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
            rail[x].flow += res.first;
            rail[e.prev_position].flow -= res.first;
        }
    }
}
