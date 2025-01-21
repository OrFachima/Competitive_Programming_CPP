#include <bits/stdc++.h>
using namespace std;

// Common macros for faster coding
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (int i = a; i < b; ++i)

// Constants
const int MOD = 1e9 + 7; // Common mod value
const int INF = 1e9;     // Infinity for graphs/DP

// Graph structure
vector<vector<int>> adj; // Adjacency list for the graph
vector<bool> visited;    // Visited array for DFS/BFS

// Input graph
void inputGraph(int &n, int &m, bool directed = false) {
    cin >> n >> m; // Number of nodes and edges
    adj.resize(n + 1); // Resize adjacency list to fit nodes
    visited.resize(n + 1, false); // Initialize visited array

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v; // Edge between u and v
        adj[u].pb(v);
        if (!directed) {
            adj[v].pb(u); // Add reverse edge for undirected graphs
        }
    }
}

// Example DFS function
void dfs(int node) {
    visited[node] = true;
    cout << "Visited node: " << node << endl;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

// Example BFS function
void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << "Visited node: " << node << endl;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

void solve() {
    int n, m;
    inputGraph(n, m, false); // Read undirected graph

    // Call DFS or BFS
    cout << "DFS Traversal:" << endl;
    dfs(1); // Start DFS from node 1
    fill(all(visited), false); // Reset visited array for BFS

    cout << "BFS Traversal:" << endl;
    bfs(1); // Start BFS from node 1
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; // Number of test cases
    // cin >> t; // Uncomment if multiple test cases
    while (t--) solve();

    return 0;
}
