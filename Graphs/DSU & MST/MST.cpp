#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

vector<int> par;

int fnd(int ch) {
    if (ch == par[ch]) return ch; // returns the representative
    else return par[ch] = fnd(par[ch]); // path compression
}

bool uni(int f, int s) {
    f = fnd(f), s = fnd(s); // representative of each node
    if (f == s) return false; // ignore, they already connected
    return par[f] = s, true; // connect them
}

int main() {
    IO;
    int n, m;
    cin >> n >> m;
    par.resize(n);
    iota(par.begin(), par.end(), 0);
    vector<array<int, 3>> edges (m);
    for (auto &[w, u, v] : edges) {
        cin >> u >> v >> w;
        u--; v--;
    }
    sort(edges.begin(), edges.end()); // sort by Weight
    int sum = 0;
    for (auto &[w, u, v] : edges) {
        if (uni(u, v)) {
            sum += w;
        }
    }
    cout << sum << endl;
    return 0;
}
