///*** https://vjudge.net/problem/UVA-11686 ***///

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

bool dfs(vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& recStack, int cur, stack<int>& stk) {
    vis[cur] = true;
    recStack[cur] = true;
    for (int i : adj[cur]) {
        if (recStack[i]) return true;
        if (!vis[i]) {
            if (dfs(adj, vis, recStack, i, stk)) {
                return true;
            }
        }
    }
    recStack[cur] = false;
    stk.push(cur);
    return false;
}

pair<bool, vector<int>> dfsHelper(vector<vector<int>>& adj, int n) {
    vector<bool> vis(n, false), recStack(n, false);;
    stack<int> stk;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (dfs(adj, vis, recStack, i, stk)){
                return {true, ans};
            }
        }
    }
    while(!stk.empty()) {
        ans.push_back(stk.top());
        stk.pop();
    }
    return {false, ans};
}

int main() {
    IO;
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
    }
    auto[cycle, ans] = dfsHelper(adj, n);
    if (cycle) cout << "IMPOSSIBLE" << endl;
    else {
        for(int i : ans) cout << i + 1 << endl;
    }
    return 0;
}
