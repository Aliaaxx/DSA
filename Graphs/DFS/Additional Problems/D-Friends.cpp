///*** https://vjudge.net/problem/UVA-10608 ***///

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int DFS(set<int> adj[], vector<bool>& vis, int cur, int& maxCount) {
    vis[cur] = true;
    maxCount += 1;
    for (auto i : adj[cur]) {
        if (!vis[i]) {
            DFS(adj, vis, i, maxCount);
        }
    }
    return maxCount;
}

int maxFriends(set<int> adj[], int n) {
    vector<bool> vis(n, false);
    int ans = INT_MIN;
    for(int i = 0; i < n; i++) {
        if (!vis[i]) {
            int maxCount = 0;
            ans = max(DFS(adj, vis, i, maxCount), ans);
        }
    }
    return ans;
}

int main() {
    IO;
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int n, e;
        cin >> n >> e;
        set<int> adj[n];
        int a, b;
        while (e--) {
            cin >> a >> b;
            adj[a - 1].insert(b - 1);
            adj[b - 1].insert(a - 1);
        }
        cout << maxFriends(adj, n) << endl;
    }
    return 0;
}
