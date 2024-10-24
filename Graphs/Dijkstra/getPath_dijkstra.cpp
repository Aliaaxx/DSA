#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

pair<vector<ll>, vector<int>> dijkstra(int src, vector<vector<pair<int, ll>>>& adj) {
    int n = (int)adj.size();
    vector<ll> dist(n, 2e18); // LLONG_MAX
    dist[src] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push({dist[src], src});
    vector<int> par(n, -1);
    while (!pq.empty()) {
        auto [dis, cur] = pq.top();
        pq.pop();
        if (dist[cur] < dis) continue;
        for (auto& [i, w] : adj[cur]) {
            if (dist[i] > dis + w) {
                dist[i] = dis + w;
                par[i] = cur;
                pq.push({dist[i], i});
            }
        }
        return {dist, par};
    }
}

vector<int> getPath(int src, int dest, vector<& par) {
    vector<int> path;
    int cur = dest;
    while (cur!= src) {
        path.push_back(cur);
        cur = par[cur];
    }
    path.push_back(src);
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    IO;
    return 0;
}
