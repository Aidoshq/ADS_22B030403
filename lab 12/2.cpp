#include <iostream> 
#include <vector>
#include <algorithm> 
#include <set> 

using namespace std; 

#define INF 1e9
int N = 200005;
vector <pair <int,int> > g[200005]; 
vector <int> d(N, INF); 
int n, m; 

int dijkstra(int from, int to) {
	d.clear();
	for(int i = 0; i < N; i++) {
		d[i] = INF;
	}
	d[from] = 0;
	set <pair <int, int> > q;
	q.insert(make_pair(d[from], from));
	while(!q.empty()) {
		int v = q.begin()->second;
		q.erase(q.begin());
		for(int i = 0; i < g[v].size(); i++) {
			int y = g[v][i].first;
			int len = g[v][i].second;
			if(d[v] + len < d[y]) {
				q.erase(make_pair(d[y], y));
				d[y] = d[v] + len;
				q.insert(make_pair(d[y], y));
			}
		}
	}
	return d[to];
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int v, u, c;
		cin >> v >> u >> c;
		g[v].push_back(make_pair(u, c));
		g[u].push_back(make_pair(v, c));
	}

	int s, a, b, f;
	cin >> s >> a >> b >> f;

	int x = dijkstra(s, a) + dijkstra(a, b) + dijkstra(b, f);
	int y = dijkstra(s, b) + dijkstra(b, a) + dijkstra(a, f); 

	if(min(x, y) <= INF) {
		cout << min(x, y) << "\n";
	} else {
		cout << "-1\n";
	}

	return 0;
}