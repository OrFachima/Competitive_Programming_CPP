#include <bits/stdc++.h>
using namespace std;

// Tarjan's Algorithm to find SCCs
class TarjanSCC {
private:
    int n;                           // Number of nodes
    vector<vector<int>> adj;         // Adjacency list
    vector<int> disc, low, inStack;  // Discovery time, Lowest link, and Stack presence
    stack<int> st;                   // Stack for Tarjan
    vector<vector<int>> sccs;        // List of all SCCs
    int timer;                       // Timer to assign discovery times

    void dfs(int u) {
        disc[u] = low[u] = ++timer; // Initialize discovery and low values
        st.push(u);
        inStack[u] = true;

        for (int v : adj[u]) {
            if (disc[v] == -1) { // If v is not visited
                dfs(v);
                low[u] = min(low[u], low[v]); // Update low value
            } else if (inStack[v]) {
                low[u] = min(low[u], disc[v]); // Update low value for back edge
            }
        }

        // If u is the root of an SCC
        if (low[u] == disc[u]) {
            vector<int> component;
            while (true) {
                int node = st.top();
                st.pop();
                inStack[node] = false;
                component.push_back(node);
                if (node == u) break;
            }
            sccs.push_back(component); // Add this SCC to the list
        }
    }

public:
    TarjanSCC(int nodes) {
        n = nodes;
        adj.resize(n + 1);
        disc.assign(n + 1, -1);
        low.assign(n + 1, -1);
        inStack.assign(n + 1, false);
        timer = 0;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    vector<vector<int>> findSCCs() {
        for (int i = 1; i <= n; ++i) {
            if (disc[i] == -1) { // If node i is unvisited
                dfs(i);
            }
        }
        return sccs;
    }
};

void solve() {
    int n, m; // n = number of nodes, m = number of edges
    cin >> n >> m;

    TarjanSCC tarjan(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        tarjan.addEdge(u, v);
    }

    vector<vector<int>> sccs = tarjan.findSCCs();

    // Output the SCCs
    cout << "Strongly Connected Components:\n";
    for (const auto& component : sccs) {
        for (int node : component) {
            cout << node << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
