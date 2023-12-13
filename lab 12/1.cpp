#include <iostream>

#include <vector>

#include <algorithm>
 
using namespace std;
 
int n, g[501][501], x[501];
bool used[501];
int main() {
	int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> g[i][j];
        }
    }

    for(int i = 1; i <= n; i++) {
        cin >> x[i];
    }

	vector <int> v;
    for(int k = 1; k <= n; k++) {
        used[x[k]] = true;
        int tmp = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) { 
                g[i][j] = min(g[i][j], g[i][x[k]] + g[x[k]][j]);
                if(used[i] && used[j]) {
                    tmp = max(g[i][j], tmp);
                }
            }
        }
        v.push_back(tmp);
    }

    for(int i = 0; i < v.size(); i++) {
		printf("%d\n", v[i]);
	}

	return 0;
}