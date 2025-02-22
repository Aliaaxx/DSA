///*** https://codeforces.com/problemset/problem/115/A ***///

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
 
int DFS(vector<int> adj[], vector<bool>& vis, int cur) {
    vis[cur] = true;
    int maxCount = 0;
    for (auto i : adj[cur]) {
        maxCount = max(maxCount, DFS(adj, vis, i));
    }
    return maxCount + 1;
}
 
int countGroups(vector<int> adj[], int n) {
    vector<bool> vis(n, false);
    int ans = INT_MIN;
    for(int i = 0; i < n; i++) {
        if (!vis[i]) {
            ans = max(ans, DFS(adj, vis, i));
        }
    }
    return ans;
}
 
int main() {
    IO;
    int n, e;
    cin >> n;
    vector<int> adj[n];
    for (int i = 0; i < n; i++) {
        cin >> e;
        if (e == -1) continue;
        adj[e - 1].push_back(i);
    }
    cout << countGroups(adj, n);
    return 0;
}
