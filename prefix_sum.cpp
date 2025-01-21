#include <bits/stdc++.h>
using namespace std;

// Example of using prefix sum to efficiently calculate range sums
void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> arr(n), prefix(n + 1, 0);

    // Calculate prefix sums
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        prefix[i + 1] = prefix[i] + arr[i];
    }

    // Answer range sum queries
    while (q--) {
        int l, r;
        cin >> l >> r; // 1-based indexing
        cout << prefix[r] - prefix[l - 1] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
