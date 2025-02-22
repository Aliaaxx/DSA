///*** https://codeforces.com/problemset/problem/29/C ***///

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
//using ll = long long;
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

void dfs(map<int, vector<int>>& adj, map<int, bool>& vis, int cur) {
    vis[cur] = true;
    cout << cur << " ";
    for (int i : adj[cur]) {
        if (!vis[i]) {
            dfs(adj, vis, i);
        }
    }
}

int main() {
    IO;
    int n, a, b;
    cin >> n;
    map<int, bool> vis;
    map<int, vector<int>> adj;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        vis[a] = false;
        vis[b] = false;
    }
    for (auto it = adj.begin(); it != adj.end(); it++) {
        if (it->second.size() == 1) {
            dfs(adj, vis, it->first);
            break;
        }
    }
    return 0;
}
