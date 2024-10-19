///*** https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1549 ***///

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

vector<int> id, sz;

int find(int e) {
    if (id[e] == e) return e; // returns the representative
    else return id[e] = find(id[e]); // path compression
}

bool uni(int f, int s) {
    f = find(f), s = find(s); // representative of each node
    if (f == s) return false; // ignore, they already connected
    return id[f] = s, sz[s] += sz[f], sz[f] = 0, true; // connect them
}

int main() {
    IO;
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        id.resize(n);
        iota(id.begin(), id.end(), 0);
        sz.assign(n, 1);
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
