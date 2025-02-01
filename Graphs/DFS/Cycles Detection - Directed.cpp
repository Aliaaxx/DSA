#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
//using ll = long long;
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

bool dfsCycles(vector<vector<int>>& adj, int src, vector<bool>& vis, vector<bool>& recStack) {
    vis[src] = true;
    recStack[src] = true;
    for (int i : adj[src]) {
        if (recStack[i]) return true;
        if (!vis[i]) {
            if (dfsCycles(adj, i, vis, recStack))  {
                return true;
            }
        }
    }
    recStack[src] = false;
    return false;
}

bool isCyclic(vector<vector<int>>& adj, int n) {
    vector<bool> vis(n, false), recStack(n, false);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (dfsCycles(adj, i, vis, recStack)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    IO;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }
    cout << isCyclic(adj, n);
    return 0;
}
