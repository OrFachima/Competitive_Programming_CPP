#include <bits/stdc++.h>
using namespace std;

// Kosaraju's Algorithm for Strongly Connected Components (SCC)

void dfs1(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs1(neighbor, adj, visited, st);
        }
    }
    st.push(node);
}

void dfs2(int node, vector<vector<int>>& revAdj, vector<bool>& visited, vector<int>& component) {
    visited[node] = true;
    component.push_back(node);
    for (int neighbor : revAdj[node]) {
        if (!visited[neighbor]) {
            dfs2(neighbor, revAdj, visited, component);
        }
    }
}

void solve() {
    int n, m; // n = number of nodes, m = number of edges
    cin >> n >> m;

    vector<vector<int>> adj(n + 1), revAdj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);      // Original graph
        revAdj[v].push_back(u);   // Transposed graph
    }

    // Step 1: Perform DFS and push nodes into stack based on finish time
    vector<bool> visited(n + 1, false);
    stack<int> st;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs1(i, adj, visited, st);
        }
    }

    // Step 2: Perform DFS on transposed graph
    fill(visited.begin(), visited.end(), false);
    vector<vector<int>> scc; // Store all SCCs
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!visited[node]) {
            vector<int> component;
            dfs2(node, revAdj, visited, component);
            scc.push_back(component);
        }
    }

    // Output all SCCs
    cout << "Strongly Connected Components:\n";
    for (auto& component : scc) {
        for (int node : component) {
            cout << node << " ";
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
