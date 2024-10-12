///*** https://www.spoj.com/problems/BITMAP/ ***///

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
    IO;
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> dist(n, vector<int> (m, -1));
        queue<pair<int, int>> q;
        char x;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                cin >> x;
                if (x == '1') {
                    dist[r][c] = 0;
                    q.push({r, c});
                }
            }
        }
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i], nc = c + dy[i];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                if (dist[nr][nc] != -1) continue;
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
        for (auto r : dist) {
            for (auto el : r) {
                cout << el << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
