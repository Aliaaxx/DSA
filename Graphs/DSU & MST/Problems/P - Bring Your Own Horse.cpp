///*** https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3328 ***///

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
    int t;
    cin >> t;
    for (int j = 0; j < t; ++j) {
        cout << "Case " << j + 1 << endl;
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
        vector<vector<pair<int, int>>> adj(n);
        for (auto &[w, u, v] : edges) {
            if (uni(u, v)) {
                adj[u].push_back({v, w});
                adj[v].push_back({u, w});
            }
        }
        int Q;
        cin >> Q;
        while (Q--) {
            int src, dst;
            cin >> src >> dst;
            src--;
            dst--;
            vector<int> dist(n, -1);
            dist[src] = 0;
            queue<pair<int, int>> q;
            q.push({src, 0});
            while (!q.empty()) {
                auto [cur, mx] = q.front();
                q.pop();
                for (auto &[i, w]: adj[cur]) {
                    if (dist[i] == -1) {
                        dist[i] = max(mx, w);
                        q.push({i, dist[i]});
                    }
                }
            }
            cout << dist[dst] << endl;
        }
        cout << endl;
    }
    return 0;
}
