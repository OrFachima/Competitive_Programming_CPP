#include <bits/stdc++.h>
using namespace std;

// Bellman-Ford Algorithm to detect negative weight cycles and find shortest paths
void solve() {
    int n, m; // n = number of nodes, m = number of edges
    cin >> n >> m;

    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    int source;
    cin >> source;

    vector<int> dist(n + 1, INT_MAX);
    dist[source] = 0;

    for (int i = 1; i <= n - 1; ++i) {
        for (auto [u, v, w] : edges) {
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative weight cycles
    for (auto [u, v, w] : edges) {
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            cout << "Graph contains a negative weight cycle.\n";
            return;
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << "Distance from " << source << " to " << i << " is " << dist[i] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

