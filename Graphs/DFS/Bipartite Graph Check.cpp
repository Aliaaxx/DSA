#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

bool DFSisBipartite(vector<int> adj[], vector<int>& color, vector<bool>& vis,int cur, int c) {
    color[cur] = c;
    vis[cur] = true;
    for (auto &i : adj[cur]) {
        if (color[i] == -1) { // not Colored
            if (!DFSisBipartite(adj, color, vis,i, c ^ 1)) {
                return false; // b3ml propagate ll false el7slt
            }
        }
        else if (color[i] == c) {
            return false;
        }
    }
    return true;
}

bool isBipartite(vector<int> adj[], int n) {
    vector<int> color(n, -1);
    vector<bool> vis(n, false);
    bool isBipartite = true;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            isBipartite &= DFSisBipartite(adj, color, vis, i, 0);
        }
    }
    return isBipartite;
}

int main() {
    IO;
    int n, edges;
    cin >> n >> edges;
    int u, v;
    vector<int> adj[n];
    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << (isBipartite(adj, n) ? "Bipartite Graph" : "Not Bipartite Graph") << endl;
    return 0;
}
