///*** https://codeforces.com/contest/1661/problem/B ***///

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
//using ll = long long;
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
 
int N = 32768;
 
int bfs(int num) {
    queue<int> q;
    q.push(num);
    vector<int> dist(N, -1);
    dist[num] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        int op1 = (cur + 1) % N;
        if (op1 == 0) {
            dist[op1] = dist[cur] + 1;
            return dist[op1];
        }
        else if (dist[op1] == -1){
            dist[op1] = dist[cur] + 1;
            q.push(op1);
        }
 
        int op2 = (2 * cur) % N;
        if (op2 == 0) {
            dist[op2] = dist[cur] + 1;
            return dist[op2];
        }
        else if (dist[op2] == -1){
            q.push(op2);
            dist[op2] = dist[cur] + 1;
        }
    }
    return 0;
}
 
int main() {
    IO;
    int n, num;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (num == 0) cout << "0" << " ";
        else cout << bfs(num) << " ";
    }
    return 0;
}
