#include <iostream>

using namespace std;

int main() {
    int n, q; cin >> n >> q;

    int adj[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }

    while(q--) {
        int x, y, z;
        cin >> x >> y >> z;
        x--; y--; z--;
        if(adj[x][y] && adj[x][z] && adj[y][z]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}