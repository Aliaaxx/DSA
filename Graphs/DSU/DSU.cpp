#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

vector<int> id;

int find(int e) {
    if (id[e] == e) return e; // returns the representative
    else return id[e] = find(id[e]); // path compression
}

bool uni(int u, int v) {
    u = find(u), v = find(v); // representative of each node
    if (u == v) return false; // ignore, they already connected
    return id[u] = v, true; // connect them
}

int main() {
    IO;
    int n, m;
    cin >> n >> m;
    id.resize(n);
    iota(id.begin(), id.end(), 0);
    for (int i = 0; i < m; ++i) {
        int e, v;
        cin >> e >> v;
        e--; v--;
        uni(e, v);
    }
    int q;
    cin >> q;
    while (q--) {
        int e, v;
        cin >> e >> v;
        e--; v--;
        cout << ((find(e) == find(v)) ? "YES" : "NO") << endl;
    }
    return 0;
}
