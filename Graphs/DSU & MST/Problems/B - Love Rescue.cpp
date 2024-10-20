///*** https://codeforces.com/problemset/problem/939/D ***///

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

vector<int> par;

int fnd(int ch) {
    if (ch == par[ch]) return ch; // returns the representative
    else return par[ch] = fnd(par[ch]); // path compression
}

bool uni(int f, int s) {
    f = fnd(f), s = fnd(s); // representative of each node
    if (f == s) return false; // ignore, they already connected
    return par[f] = s, true; // connect them
}

int main() {
    IO;
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    par.resize(26);
    iota(par.begin(), par.end(), 0);
    vector<bool> vis(26, false);
    vector<pair<char, char>> ans;
    for (int i = 0; i < n; i++) {
        if (uni(a[i] - 'a', b[i] - 'a')) {
            ans.push_back({a[i], b[i]});
        }
    }
    cout << ans.size() << endl;
    for (auto &[x, y] : ans) {
        cout << x << " " << y << endl;
    }
    return 0;
}
