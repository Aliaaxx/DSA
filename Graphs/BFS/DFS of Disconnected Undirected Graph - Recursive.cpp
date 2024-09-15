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

vector<int> DFS (vector<vector<int>> adj, int num_vertices) {
    vector<bool> visited(num_vertices, false);
    vector<int> ans;
    for (int i = 0; i < num_vertices; i++) {
        if (!visited[i]) {
            DFSRec(adj, i, visited, ans);
        }
    }
    return ans;
}

int main() {
    IO;
    int v = 6;
    vector<pair<int, int>> edges = {{1, 2}, {2, 0}, {0, 3}, {4, 5}};
    vector<vector<int>> adjacency = EdgesToAdj(edges, v);
    vector<int> res = DFS(adjacency, v);
    for (int i : res) {
        cout << i << " ";
    }
    return 0;
}
