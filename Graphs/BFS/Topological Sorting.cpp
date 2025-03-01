
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
//using ll = long long;
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

vector<int> topologicalSortBFS(vector<vector<int>>& adj, vector<int>& in) {
    int n = adj.size();
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }
    vector<int> order;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        order.push_back(cur);
        for (int i : adj[cur]) {
            in[i]--;
            if (in[i] == 0) {
                q.push(i);
            }
        }
    }
    return order;
}

int main() {
    IO;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> in(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].emplace_back(v);
        in[v]++;
    }
    auto order = topologicalSortBFS(adj, in);
    if (order.size() != n) cout << "Cycle Exists!" << endl;
    else for (int i : order) cout << i + 1 << " ";
    return 0;
}
