#include <bits/stdc++.h>
using namespace std;

// Floyd-Warshall Algorithm to find all-pairs shortest paths
void solve() {
    int n, m; // n = number of nodes, m = number of edges
    cin >> n >> m;

    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INT_MAX));

    for (int i = 1; i <= n; ++i) dist[i][i] = 0;

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
        // dist[v][u] = w; // Uncomment for undirected graphs
    }

    // Floyd-Warshall
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Print the shortest distances
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dist[i][j] == INT_MAX) cout << "INF ";
            else cout << dist[i][j] << " ";
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
