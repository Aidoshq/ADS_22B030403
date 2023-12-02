#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <vector <int> > g(100001);
vector <bool> used(100001);
vector <int> components;

void dfs(int v) {
    used[v] = true;
    components.push_back(v);
    for(int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if(!used[to]) {
            dfs(to);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    while(m--) {
        int a, b; 
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int x, y;
    cin >> x >> y;
    dfs(x);
    for(int i = 0; i < components.size(); i++) {
        // cout << components[i] << " ";
        if(y == components[i]) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";

    return 0;
}