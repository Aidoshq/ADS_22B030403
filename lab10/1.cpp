#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int arr[n + 2][m + 2];
    vector <pair <int, int> > marios;
    int mushrooms = 0;
    for(int i = 0; i < n + 2; i++) {
        for(int j = 0; j < m + 2; j++) {
            if(i == 0 || j == 0 || i == n + 1 || j == m + 1) {
                arr[i][j] = 1000;
                continue;
            }
            cin >> arr[i][j];
            if(arr[i][j] == 2) {
                marios.push_back(make_pair(i, j));
            } else if(arr[i][j] == 1) {
                mushrooms++;
            }
        }
    }

    queue <pair <int, int> > q;
    for(int i = 0; i < marios.size(); i++) {
        q.push(make_pair(marios[i].first, marios[i].second));
    }

    int time = 0;
    while(!q.empty()) {
        if(!mushrooms) {
            break;
        }
        int size = q.size();
        while(size--) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if(arr[i - 1][j] == 1) {
                arr[i - 1][j] = 2;
                q.push(make_pair(i - 1, j));
                mushrooms--;
            }
            if(arr[i + 1][j] == 1) {
                arr[i + 1][j] = 2;
                q.push(make_pair(i + 1, j));
                mushrooms--;
            }
            if(arr[i][j - 1] == 1) {
                arr[i][j - 1] = 2;
                q.push(make_pair(i, j - 1));
                mushrooms--;
            }
            if(arr[i][j + 1] == 1) {
                arr[i][j + 1] = 2;
                q.push(make_pair(i, j + 1));
                mushrooms--;
            }
        }
        time++;
    }

    if(!mushrooms) {
        cout << time << "\n";
    } else {
        cout << "-1\n";
    }

    return 0;
}