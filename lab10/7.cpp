#include <iostream>
#include <vector>

using namespace std;

vector <vector <int> > g(501);
vector <int> states(501);

bool detectCycle(int v, pair <int, int> edge) {
    states[v] = 1;
    for(int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if(v == edge.first && to == edge.second) {
            continue;
        }
        if(states[to] == 0) {
            if(detectCycle(to, edge)) {
                return true;
            }
        } else if(states[to] == 1) {
            return true;
        }
    }
    states[v] = 2;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < g[i].size(); j++) {
            bool hasCycle = false;
            for(int k = 0; k < n; k++) {
                if(detectCycle(k, make_pair(i, g[i][j]))) {
                    hasCycle = true;
                    break;
                }
            }
            if(!hasCycle) {
                cout << "YES\n";
                return 0;
            }
            states.assign(n, 0);
        }
    }
    cout << "NO\n";

    return 0;
}