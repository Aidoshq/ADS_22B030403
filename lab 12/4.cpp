#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int from, to, cost;
    Edge(int from, int to, int cost) {
        this->from = from;
        this->to = to;
        this->cost = cost;
    }
};
vector <Edge> edges;
int n, m;

int fordBellman(int s, int f) {
	vector<int> d(n, 1e9);
	int age = 0;
	d[s] = age;
	while (true) {
		bool hasChanged = false;
		for (int j = 0; j < m; j++) {
			if (d[edges[j].to] > d[edges[j].from] + edges[j].cost) {
				d[edges[j].to] = d[edges[j].from] + edges[j].cost;
				hasChanged = true;
			}
		}
		if (!hasChanged) { 
            break;
        }
	}
	return d[f];
}

int main() {
    cin >> n;
    vector <pair <int, int> > cities(n);
    for(int i = 0; i < n; i++) {
        int from, to;
        cin >> from >> to;
        cities[i] = make_pair(from, to);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) {
                continue;
            }
            int cost = abs(cities[i].first - cities[j].first) + abs(cities[i].second - cities[j].second);
            edges.push_back(Edge(i, j, cost));
        }
    }
    fordBellman(0, n - 1);

    return 0;
}