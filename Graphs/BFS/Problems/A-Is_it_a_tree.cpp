///*** https://www.spoj.com/problems/PT07Y/ ***///

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
//using ll = long long;
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

bool isTree (int m, vector<vector<int>>& adj) {
    int n = (int) adj.size();
    if (m != (n - 1)) return false;
    queue<int> q;
    q.push(0);
    vector<int> vis(n, 0);
    int cnt = 1;
    vis[0] = 1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i : adj[cur]) {
            if (vis[i] == 0) {
                cnt += 1;
                vis[i] = 1;
                q.push(i);
            }
        }
    }
    return (cnt == n);
}

int main() {
    IO;
    int n, m, u, v;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << (isTree(m, adj) ? "Yes" : "No") << endl;
    return 0;
}
