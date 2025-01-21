#include <bits/stdc++.h>
using namespace std;

class UnionFind {
    vector<int> parent, rank;

public:
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    int n = 5; // Number of elements
    UnionFind uf(n);

    uf.unite(0, 1);
    uf.unite(1, 2);
    uf.unite(3, 4);

    cout << "Are 0 and 2 connected? " << (uf.connected(0, 2) ? "Yes" : "No") << endl;
    cout << "Are 0 and 4 connected? " << (uf.connected(0, 4) ? "Yes" : "No") << endl;

    uf.unite(2, 3);
    cout << "Are 0 and 4 connected after unite(2, 3)? " << (uf.connected(0, 4) ? "Yes" : "No") << endl;

    return 0;
}
