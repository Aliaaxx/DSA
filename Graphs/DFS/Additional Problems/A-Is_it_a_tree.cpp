///*** https://www.spoj.com/problems/PT07Y/en/ ***///

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

void dfsRec (vector<bool> &vis, vector<vector<int>>& adj, int node) {
    vis[node] = true;
    for (int i = 0; i < adj[node].size(); i++) {
        if (!vis[adj[node][i]]) {
            dfsRec(vis, adj, adj[node][i]);
        }
    }
}

int dfs (vector<vector<int>>& adj, int n) {
    vector<bool> vis(n, false);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            cnt += 1;
            dfsRec(vis, adj, i);
        }
    }
    return cnt;
}

int main() {
    IO;
    int n, m;
    cin >> n >> m;
    int a, b;
    if (m != n - 1) {
        cout << "NO" << endl;
    }  
    else {
        vector<vector<int>> adj(n);
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            adj[a - 1].push_back(b - 1);
            adj[b - 1].push_back(a - 1);
        }
        if (dfs(adj, n) == 1) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
