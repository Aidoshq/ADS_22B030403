#include <iostream>
#include <vector>

using namespace std;

vector <vector <int> > g;
vector <bool> used;
vector <int> min_e, p;

#define INF 1e9

int main() {
    int n; cin >> n;
    g.resize(n);
    for(int i = 0; i < n; i++) {
        g[i].resize(n);
    }

    used.resize(n);
    p.assign(n, -1);
    min_e.assign(n, INF);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }

    min_e[0] = 0;
    int res = 0;
    for(int i = 0; i < n; i++) {
        int v = -1;
        for(int j = 0; j < n; j++) {
            if(!used[j] && (v == -1 || min_e[j] < min_e[v])) {
                v = j;
            }
        }
        used[v] = true;
        if(p[v] != -1) {
            res += g[v][p[v]];
        }
        for(int j = 0; j < n; j++) {
            if(g[v][j] < min_e[j]) {
                min_e[j] = g[v][j];
                p[j] = v;
            }
        }
    }
    cout << res << "\n";

    return 0;
}