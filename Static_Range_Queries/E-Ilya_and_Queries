///*** https://codeforces.com/contest/313/problem/B ***///

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
 
int main() {
    IO;
    string s;
    cin >> s;
    int q;
    cin >> q;
    vector<int> pre(s.size());
    if (s[0] == s[1]) {
        pre[1] = 1;
    }
    for (int i = 1; i < s.size() - 1; i++) {
        if (s[i] == s[i + 1]) {
            pre[i+1] += 1;
        }
        pre[i + 1] += pre[i];
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << pre[r - 1] - pre[l - 1] << endl;
    }
    return 0;
}
