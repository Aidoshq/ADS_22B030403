#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, q;
vector <vector <int> > g;
vector <bool> used, colors;

int bfs(int v) {
    if(colors[v]) {
        return 0;
    }
    used[v] = true;
    int cnt = 0;
    queue <int> q;
    q.push(v);
    while(!q.empty()) {
        cnt++;
        int a = q.front();
        q.pop();
        for(int i = 0; i < g[a].size(); i++) {
            int to = g[a][i];
            if(!used[to]) {
                used[to] = true;
                if(colors[to]) {
                    for(int j = 0; j < n; j++) {
                        used[j] = false;
                    }
                    return cnt;
                } else {
                    q.push(to);
                }
            }
        }
    }
    for(int j = 0; j < n; j++) {
        used[j] = false;
    }
    return -1;
}

int main() {
    cin >> n >> m >> q;

    g.resize(n);
    used.resize(n);
    colors.resize(n);

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    while(q--) {
        int command, v;
        cin >> command >> v;
        v--;
        if(command == 1) {
            colors[v] = true;
        } else if(command == 2) {
            cout << bfs(v) << "\n";
        }
    }

    return 0;
}