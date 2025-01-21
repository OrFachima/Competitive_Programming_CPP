#include <bits/stdc++.h>
using namespace std;

// Dijkstra's Algorithm to find the shortest path from a single source
void dijkstra(int source, vector<vector<pair<int, int>>>& adj, vector<int>& dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, source});
    dist[source] = 0;

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, weight] : adj[u]) {
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

void solve() {
    int n, m; // n = number of nodes, m = number of edges
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Uncomment this for undirected graphs
    }

    int source;
    cin >> source;

    vector<int> dist(n + 1, INT_MAX);
    dijkstra(source, adj, dist);

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
