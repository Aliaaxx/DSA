#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

vector<vector<int>> EdgesToAdj(vector<pair<int, int>> edges, int v) {
    vector<vector<int>> adj(v);
    for (auto [a, b] : edges) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    return adj;
}

void DFSRec (vector<vector<int>> adj, int s, vector<bool>& visited, vector<int>& ans) {
    ans.push_back(s);
    visited[s] = true;
    for (int i : adj[s]) {
        if (!visited[i]) {
            DFSRec(adj, i, visited, ans);
        }
    }
}

int DFS (vector<vector<int>> adj, int num_vertices) {
    vector<bool> visited(num_vertices, false);
    vector<int> ans;
    int count = 0;
    for (int i = 0; i < num_vertices; i++) {
        if (!visited[i]) {
            DFSRec(adj, i, visited, ans);
            count += 1;
        }
    }
    return count;
}

int main() {
    IO;
    int v = 6;
    vector<pair<int, int>> edges = {{1, 2}, {2, 0}, {0, 3}, {4, 5}};
    vector<vector<int>> adj = EdgesToAdj(edges, v);
    cout << DFS(adj, v) << endl;
    return 0;
}
