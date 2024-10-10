#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

vector<int> BFS(int src, vector<vector<int>>& adj) {
    int n = (int)adj.size();
    vector<int> dis(n, -1);
    queue<int> q;
    q.push(src);
    dis[src] = 0;
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        for (int node : adj[i]) {
            if (dis[node] == -1) {
                q.push(node);
                dis[node] = dis[i] + 1;
            }
        }
    }
    return dis;
}

int main() {
    IO;
    int n, m;
    cin >> n >> m;
    int a, b;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    auto ans = BFS(0, adj);
    for (int i = 0; i < n; ++i) {
        cout << "The Distance you must walk form your home to reach node " << i + 1 << " is " << ans[i] << endl;
    }
    return 0;
}
