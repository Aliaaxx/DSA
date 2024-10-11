#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

pair<vector<int>, vector<int>> BFS(int src, vector<vector<int>>& adj) {
    int n = (int)adj.size();
    vector<int> dis(n, -1), par(n, -1);
    queue<int> q;
    q.push(src);
    dis[src] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int node : adj[cur]) {
            if (dis[node] == -1) {
                q.push(node);
                dis[node] = dis[cur] + 1;
                par[node] = cur;
            }
        }
    }
    return {dis, par};
}

vector<int> getPath(int src, int dest, vector<int>& par) {
    vector<int> path;
    int cur = dest;
    while(cur != src) {
        path.push_back(cur);
        cur =par[cur];
    }
    path.push_back(src);
    reverse(path.begin(), path.end());
    return path;
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
    auto [dist, par] = BFS(0, adj);
    for (int i = 0; i < n; i++) {
        cout << "The Distance you must walk form your home to reach node " << i + 1 << " is " << dist[i] << endl;
        cout << "The Path you must follow to reach node " << i + 1 << " is ";
        vector<int> path = getPath(0, i, par);
        for (auto &j : path) {
            cout << j + 1 << " ";
        }
        cout <<"\n---------------------------------------------------------------" << endl;
    }
    return 0;
}
