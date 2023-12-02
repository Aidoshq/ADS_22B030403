#include <iostream>

#include <vector>

#include <queue>

using namespace std;

const int N = 101;
int n;
int adj[N][N];
vector <bool> used;

int minDistance(int from, int to) {
    queue <pair <int, int> > q;
    q.push(make_pair(from, 0));
    used[from] = true;
    while(!q.empty() && q.front().first != to) {
        int curValue = q.front().first;
        int curDistance = q.front().second;
        used[curValue] = true;
        q.pop();
        for(int i = 0; i < n; i++) {
            if(adj[curValue][i] && !used[i]) {
                q.push(make_pair(i, curDistance + 1));
            }
        }
    }
    if(!q.empty()) {
        return q.front().second;
    }
    return -1;
}

int main() {
    cin >> n;
    used.resize(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }
    int x, y; cin >> x >> y;
    cout << minDistance(--x, --y) << "\n";

    return 0;
}