#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<ll> dijkstra(int src, vector<vector<pair<int, ll>>>& adj) {
    int n = (int)adj.size();
    vector<ll> dist(n, 2e18); // LLONG_MAX
    dist[src] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push({dist[src], src});
    while (!pq.empty()) {
        auto [dis, cur] = pq.top();
        pq.pop();
        if (dist[cur] < dis) continue;
        for (auto& [i, w] : adj[cur]) {
            if (dist[i] > dis + w) {
                dist[i] = dis + w;
                pq.push({dist[i], i});
            }
        }
        return dist;
    }
}
