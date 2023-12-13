#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int adj[401][401];
vector <int> airlanes[401];
vector <int> roadways[401];

pair <int, bool> dijkstraForRoadways(int n) {
    queue <int> q;
    vector <int> d(n + 1);
    vector <bool> used(n + 1);
    q.push(0);
    used[0] = true;

    while(!q.empty()) {
        int a = q.front();
        q.pop();
        for(int i = 0; i < roadways[a].size(); i++) {
            int b = roadways[a][i];
            if(!used[b]) {
                used[b] = true;
                q.push(b);
                d[b] = d[a] + 1;
            }
        }
    }
    return make_pair(d[n - 1], used[n - 1]);
}

pair <int, bool> dijkstraForAirlanes(int n) {
    queue <int> q;
    vector <int> d(n + 1);
    vector <bool> used(n + 1);
    q.push(0);
    used[0] = true;

    while(!q.empty()) {
        int a = q.front();
        q.pop();
        for(int i = 0; i < airlanes[a].size(); i++) {
            int b = airlanes[a][i];
            if(!used[b]) {
                used[b] = true;
                q.push(b);
                d[b] = d[a] + 1;
            }
        }
    }
    return make_pair(d[n - 1], used[n - 1]);
}

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        roadways[a].push_back(b);
        roadways[b].push_back(a);
        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i != j && adj[i][j] == 0) {
                airlanes[i].push_back(j);
            }
        }
    }

    pair <int, bool> d1 = dijkstraForRoadways(n);
    pair <int, bool> d2 = dijkstraForAirlanes(n);

    if(!d1.second || !d2.second) {
        cout << "-1\n";
    } else {
        cout << max(d1.first, d2.first) << "\n";
    }

    return 0;
}