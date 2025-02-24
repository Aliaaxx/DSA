///*** https://vjudge.net/problem/UVA-10685 ***///

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int dfs(map<string, vector<string>>& adj, map<string, bool>& vis, string cur, int& cnt) {
    cnt += 1;
    vis[cur] = true;
    for (auto i : adj[cur]) {
        if (!vis[i]) {
            dfs(adj, vis, i, cnt);
        }
    }
    return cnt;
}

int dfsHelper(map<string, vector<string>>& adj, map<string, bool>& vis) {
    int count = 0, res = 1;
    for (auto it = adj.begin(); it != adj.end(); it++) {
        if (!vis[it->first]) {
            count = 0;
            res = max(dfs(adj, vis, it->first, count), res);
        }
    }
    return res;
}

int main() {
    IO;
    int n, m;
    while(cin>> n >> m && n) {
        map<string, vector<string>> adj;
        map<string, bool> vis;
        string s;
        for (int i = 0; i < n; i++) {
            cin >> s;
        }
        string u, v;
        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            vis[u] = false;
            vis[v] = false;
        }
        cout << dfsHelper(adj, vis) << endl;
    }
    return 0;
}
