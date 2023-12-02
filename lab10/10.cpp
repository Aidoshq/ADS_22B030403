#include <iostream>
#include <vector>

using namespace std;

vector <vector <int> > g(100001);
vector <bool> used(100001);
int cnt = 0;

void dfs(int v) {
    used[v] = true;
    for(int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if(!used[to]) {
            if(g[to].size() > g[v].size()) {
                cnt++;
            }
            dfs(to);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }

    for(int i = 0; i < n; i++) {
        if(!used[i]) {
            dfs(i);
        }
    }
    cout << cnt << "\n";

    return 0;
}