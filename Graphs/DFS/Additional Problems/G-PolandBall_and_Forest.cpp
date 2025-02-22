///*** https://codeforces.com/problemset/problem/755/C ***///

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

void DFS(vector<int> adj[], vector<bool>& vis, int cur) {
    vis[cur] = true;
    for (auto i : adj[cur]) {
        if (!vis[i]) {
            DFS(adj, vis, i);
        }
    }
}

int countTrees(vector<int> adj[], int n) {
    vector<bool> vis(n, false);
    int count = 0;
    for(int i = 0; i < n; i++) {
        if (!vis[i]) {
            count += 1;
            DFS(adj, vis, i);
        }
    }
    return count;
}

int main() {
    IO;
    int n, e;
    cin >> n;
    vector<int> adj[n];
    for (int i = 0; i < n; i++) {
        cin >> e;
        adj[e - 1].push_back(i);
        adj[i].push_back(e - 1);
    }
    cout << countTrees(adj, n);
    return 0;
}
