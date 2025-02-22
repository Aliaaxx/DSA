///*** https://codeforces.com/problemset/problem/445/B ***///

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int DFS(vector<bool>& vis, vector<int> adj[], int cur, int& Num) {
    vis[cur] = true;
    Num += 1;
    for (auto i : adj[cur]) {
        if (!vis[i]) {
            DFS(vis, adj, i, Num);
        }
    }
    return Num;
}

ll dfsHelper(vector<int> adj[], int n) {
    vector<bool> vis(n);
    ll Danger = 1, cnt;
    for(int i = 0; i < n; i++) {
        if (!vis[i]) {
            int num = 0;
            cnt = DFS(vis, adj, i, num);
            if (cnt > 1) {
                cnt -= 1;
                while (cnt--) Danger *= 2;
            }
        }
    }
    return Danger;
}

int main() {
    IO;
    int n, e;
    cin >> n >> e;
    int a, b;
    vector<int> adj[n];
    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << dfsHelper(adj, n) << endl;
    return 0;
}
