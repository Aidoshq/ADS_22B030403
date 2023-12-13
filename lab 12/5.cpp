#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[101][101];
vector <pair <int, pair <int, int> > > edges;

void print(vector <int> &v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << ' ';
    }
    cout << endl;
}

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            if(a[i][j] != 100000){
                edges.push_back(make_pair(a[i][j], make_pair(i, j)));
            }
        }
    }

    vector<int> vertices(n, 1000000000);
    vector<int> parent(n, -1);
    vertices[0] = 0;
    sort(edges.begin(), edges.end());
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < edges.size(); j++){
            int cost = edges[j].first;
            int v = edges[j].second.first;
            int w = edges[j].second.second;
            if(vertices[v] + cost < vertices[w]){
                vertices[w] = vertices[v] + cost;
                parent[w] = v;
            }
        }
    }

    int start = -1;
    for(int i = 0; i < edges.size(); i++) {
        int v = edges[i].second.first;
        int u = edges[i].second.second;
        int cost = edges[i].first;
        if(vertices[v] + cost < vertices[u] && vertices[v] < 100001) {
            if(start == -1) {
                start = v;
                break;
            }
        }
    }

    if(start == -1) {
        cout << "NO\n";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        start = parent[start];
    }

    vector<int> cycle;
    for (int v = start; ; v = parent[v]) {
        cycle.push_back(v);
        if (v == start && cycle.size() > 1) {
            break;
        }
    }

    reverse(cycle.begin(), cycle.end());
    cout << "YES\n" << cycle.size() << "\n";
    for(int i = 0; i < cycle.size(); i++) {
        cout << cycle[i] + 1 << " ";
    }
    cout << "\n";

    return 0;
}