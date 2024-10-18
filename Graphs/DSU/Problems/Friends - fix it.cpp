///*** https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1549 ***///

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

vector<int> id, sz;

int fnd(int e) {
    if (id[e] == e) return e;
    else return id[e] = fnd(id[e]);
}

bool uni(int u, int v) {
    u = fnd(u), v = fnd(v); // representative of each node
    if (u == v) return false; // ignore, they already connected
    return id[u] = v, sz[v] += sz[u], sz[u] = 0, true; // connect them
}

int main() {
    IO;
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        id.resize(n);
        sz.resize(n, 1);
        iota(id.begin(), id.end(), 0);
        for (int i = 0; i < m; ++i) {
            int e, v;
            cin >> e >> v;
            e--; v--;
            uni(e, v);
        }
        cout << *max_element(sz.begin(), sz.end()) << endl;
    }
    return 0;
}
