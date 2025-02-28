#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
//using ll = long long;
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

void dfs (vector<vector<int>>& adj, vector<bool>& vis, int cur, stack<int>& stk) {
    vis[cur] = true;
    for (auto i : adj[cur]) {
        if (!vis[i]) {
            dfs(adj, vis, i, stk);
        }
    }
    stk.push(cur);
}

vector<int> topologicalSortDfs(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool>vis (n, false);
    stack<int> stk;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(adj, vis, i, stk);
        }
    }
    vector<int> ans;
    while (!stk.empty()) {
        ans.push_back(stk.top());
        stk.pop();
    }
    return ans;
}

int main() {
    IO;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].emplace_back(v);
    }
    auto ans = topologicalSortDfs(adj);
    for (int i : ans) cout << i + 1 << " ";
    return 0;
}
