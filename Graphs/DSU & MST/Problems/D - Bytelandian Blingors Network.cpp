///*** https://www.spoj.com/problems/BLINNET/ ***///

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

vector<int> par;

int fnd(int ch) {
    if (ch == par[ch]) return ch;
    else return par[ch] = fnd(par[ch]);
}

bool uni(int f, int s) {
    f = fnd(f), s = fnd(s);
    if (f == s) return false;
    return par[f] = s, true;
}

int main() {
    IO;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<array<int, 3>> edges;
        par.resize(n);
        iota(par.begin(), par.end(), 0);
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            int nei;
            cin >> nei;
            while (nei--) {
                int u, w;
                cin >> u >> w;
                u--;
                edges.push_back({w, i, u});
            }
        }
        sort (edges.begin(), edges.end());
        int sum = 0;
        for (auto &[w, u, v] : edges) {
            if (uni(u, v)) {
                sum += w;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
