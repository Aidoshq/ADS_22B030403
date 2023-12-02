#include <iostream>

using namespace std;

const int N = 101;
char a[N][N];

void dfs(int i, int j, int n, int m) {
    if(i < 0 || j < 0 || i >= n || j >= m || a[i][j] == '0' || a[i][j] == '#') {
        return;
    } 
    a[i][j] = '#';
    dfs(i + 1, j, n, m);
    dfs(i - 1, j, n, m);
    dfs(i, j + 1, n, m);
    dfs(i, j - 1, n, m);
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == '1') {
                cnt++;
                dfs(i, j, n, m);
            }
        }
    }
    cout << cnt << "\n";
    

    return 0;
}