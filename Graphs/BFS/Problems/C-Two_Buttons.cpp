///*** https://codeforces.com/contest/520/problem/B ***///

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
//using ll = long long;
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
 
int bfs(int n, int m) {
    if (n >= m) {
        // If n >= m, the only operation is to subtract 1 (n - m) times
        return n - m;
    }
    queue<int> q;
    q.push(n);
    vector<int> dist(2 * m, -1);
    dist[n] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        int op1 = cur * 2;
        if (op1 == m) {
            dist[op1] = dist[cur] + 1;
            return dist[op1];
        }
        else if (op1 < 2 * m && dist[op1] == -1){
            dist[op1] = dist[cur] + 1;
            q.push(op1);
        }
 
        int op2 = cur - 1;
        if (op2 == m) {
            dist[op2] = dist[cur] + 1;
            return dist[op2];
        }
        else if (op2 > 0 && dist[op2] == -1){
            q.push(op2);
            dist[op2] = dist[cur] + 1;
        }
    }
    return 0;
}
 
int main() {
    IO;
    int n, m;
    cin >> n >> m;
    cout << bfs(n, m) << " ";
    return 0;
}
