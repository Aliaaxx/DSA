///*** https://codeforces.com/contest/277/problem/A ***///

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

vector<int> par;

int fnd(int ch) {
    if (ch == par[ch]) return ch;
    else return par[ch] = fnd(par[ch]);
}

bool uni(int f, int s) {
    f = fnd(f), s = fnd(s);
    if (f == s) return false;
    return par[f] = s, true;
}

void dfs(vector<vector<int>>& adj, vector<bool>& vis, int src) {
    vis[src] = true;
    for (int node : adj[src]) {
        if (!vis[node]) dfs(adj, vis, node);
    }
}

int dfsHelper(vector<vector<int>>& adj, int n) {
    vector<bool> vis(n, false);
    int cnt = 0;
    for (int i = 0 ;i < n; i++) {
        if (!vis[i] and !adj[i].empty()) {
            dfs(adj, vis, i);
            cnt ++;
        }
    }
    return cnt;
}

int main() {
    IO;
    int n, m;
    cin >> n >> m;
    int ans = 0;
    par.resize(m);
    iota(par.begin(), par.end(), 0);
    vector<vector<int>> adj(m);
    while (n--) {
        int x;
        cin >> x;
        if (x == 0) {
            ans += 1;
            continue;
        }
        int lang1, lang2;
        cin >> lang1;
        lang1--;
        if (x == 1) {
            adj[lang1].push_back(lang1);
        }
        for (int i = 1; i < x; i++){
            cin >> lang2;
            lang2--;
            if (uni(lang1, lang2)) {
                adj[lang1].push_back(lang2);
                adj[lang2].push_back(lang1);
            }
            lang1 = lang2;
        }
    }
    if (dfsHelper(adj, m)) ans += (dfsHelper(adj, m) - 1);
    cout << ans;
    return 0;
}
