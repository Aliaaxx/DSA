///*** https://www.spoj.com/problems/BITMAP/ ***///

// took 0.06 sec and mem 5.2 M

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

/////////////////////////////////////////////////////////////////////////
// Mapping to adjacency List
// took 0.08 sec and mem 5.5 M

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
//using ll = long long;
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main() {
    IO;
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char> (m));
        string s;
        queue<int> q;
        vector<int> dist(n * m, -1);
        for (int i = 0; i < n; i++) {
            cin >> s;
            for (int j = 0; j < m; j++) {
                grid[i][j] = s[j];
                if (s[j] == '1') {
                    q.push(i * m + j);
                    dist[i * m + j] = 0;
                }
            }
        }
        vector<vector<int>> adj(n * m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int node = i * m + j;
                // Left
                if (j > 0) {
                    int neig = i * m + (j - 1);
                    adj[node].push_back(neig);
                }
                // Right
                if (j < m - 1) {
                    int neig = i * m + (j + 1);
                    adj[node].push_back(neig);
                }
                // Up
                if (i > 0) {
                    int neig = (i - 1) * m + j;
                    adj[node].push_back(neig);
                }
                // down
                if (i < n - 1) {
                    int neig = (i + 1) * m + j;
                    adj[node].push_back(neig);
                }
            }
        }
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int &i : adj[cur]) {
                if (dist[i] == -1) {
                    dist[i] = dist[cur] + 1;
                    q.push(i);
                }
            }
        }
        int i = 0;
        for (int k : dist) {
            if (i % m == 0 and i != 0) cout << endl;
            cout << k << " ";
            i++;
        }
        cout << endl;
    }
    return 0;
}
