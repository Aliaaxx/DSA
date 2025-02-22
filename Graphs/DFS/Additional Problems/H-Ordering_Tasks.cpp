///*** https://vjudge.net/problem/UVA-10305 ***///

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

void DFS(vector<int> adj[], vector<bool>& vis, int cur, stack<int>& stk) {
    vis[cur] = true;
    for (auto i : adj[cur]) {
        if (!vis[i]) {
            DFS(adj, vis, i, stk);
        }
    }
    stk.push(cur + 1);
}

void topologicalSort(vector<int> adj[], int n) {
    vector<bool> vis(n, false);
    stack<int> stk;
    for(int i = 0; i < n; i++) {
        if (!vis[i]) {
            DFS(adj, vis, i, stk);
        }
    }
    while (!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
}

int main() {
    IO;
    while (true) {
        int n, e;
        cin >> n >> e;
        if (n == 0 and e == 0) break;
        vector<int> adj[n];
        int a, b;
        while (e--) {
            cin >> a >> b;
            adj[a - 1].push_back(b - 1);
        }
        topologicalSort(adj, n);
    }
    return 0;
}
