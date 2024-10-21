///*** https://codeforces.com/problemset/problem/1139/C ***///

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

void dfs(vector<vector<int>>& adj, vector<bool>& vis, int src, vector<int>& ans, int& cnt, int SOURCE) {
    vis[src] = true;
    cnt += 1;
    for (int node : adj[src]) {
        if (!vis[node]) {
            dfs(adj, vis, node, ans, cnt, SOURCE);
        }
    }
    if (src == SOURCE) {
        ans.push_back(cnt);
    }
}

vector<int> dfsHelper(vector<vector<int>>& adj, int n) {
    vector<bool> vis(n, false);
    int cnt = 0;
    vector<int> ans;
    for (int i = 0 ;i < n; i++) {
        if (!vis[i]) {
            dfs(adj, vis, i, ans, cnt, i);
        }
    }
    return ans;
}

int mod = 1e9 + 7;

int add(int a, int b) {
    return (a % mod + b % mod) % mod;
}

int main() {
    IO;
    int n, k;
    cin >> n >> k;
    int m = n - 1;
    vector<vector<int>> adj(n);
    while (m--) {
        int u, v, c;
        cin >> u >> v >> c;
        u--; v--;
        if (c == 0) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    auto ans = dfsHelper(adj, n);
    int bad = 0, total = pow(n, k);
    for (int i : ans) {
        bad = add(bad, (pow(i, k)));
    }
    cout << total - bad << endl;
    return 0;
}
