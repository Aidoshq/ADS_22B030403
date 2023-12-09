#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<int> gr[200500];
vector <int> p;

int dsuGet(int v) {
	if (v == p[v]) {
		return v;
	}
	return p[v] = dsuGet(p[v]);
}

bool dsuUnite(int a, int b) {
	a = dsuGet(a);
	b = dsuGet(b);
	if (a != b) {
        p[a] = b;
        return true;
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    p.resize(n);

    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }

    for(int i = 0; i < n; i++) {
        p[i] = i;
    }

    unordered_set <int> s;
    vector <int> res;
    int cnt = 0;
    for(int i = n - 1; i >= 0; i--) {
        res.push_back(cnt);
        cnt++;
        for(int j = 0; j < gr[i].size(); j++) {
            if(gr[i][j] > i && dsuUnite(i, gr[i][j])) {
                cnt--;
            }
        }
    }

    reverse(res.begin(), res.end());
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << "\n";
    }

    return 0;
}