///*** https://www.spoj.com/problems/BUGLIFE/en/ ***///

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

bool DFS(vector<int> adj[], vector<int>& color, vector<bool>& vis, int cur, int c) {
    color[cur] = c;
    vis[cur] = true;
    for (auto i : adj[cur]) {
        if (color[i] == -1) {
            if (!DFS(adj, color, vis, i, c ^ 1)) {
                return false;
            }
        }
        else if (color[i] == c){
            return false;
        }
    }
    return true;
}

bool isBipartite(vector<int> adj[], int n) {
    vector<int> color(n, -1);
    vector<bool> vis(n, false);
    bool isBipartite = true;
    for(int i = 0; i < n; i++) {
        if (!vis[i]) {
            isBipartite &= DFS(adj, color, vis, i, 0);
        }
    }
    return isBipartite;
}

int main() {
    IO;
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int n, e;
        cin >> n >> e;
        vector<int> adj[n];
        int a, b;
        while (e--) {
            cin >> a >> b;
            adj[a - 1].push_back(b - 1);
            adj[b - 1].push_back(a - 1);
        }
        cout << "Scenario #" << i << ":" << endl;
        cout << (isBipartite(adj, n) ? "No suspicious bugs found!" : "Suspicious bugs found!") << endl;
    }
    return 0;
}
