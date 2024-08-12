///*** https://codeforces.com/problemset/problem/816/B ***///

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
 
const int Max = 1e6 + 5;
int freq[Max], res[Max];
 
int main() {
    IO;
    ll n, k, q;
    cin >> n >> k >> q;
    while (n--) {
        ll l, r;
        cin >> l >> r;
        freq[l] += 1;
        freq[r + 1] -= 1;
    }
    for (ll i = 1; i < Max; i++) {
        freq[i] += freq[i - 1];
    }
    for (ll i = 0; i < Max; i++) {
        if (freq[i] >= k) {
            res[i] += 1;
        }
        if (i) res[i] += res[i - 1];
    }
    while (q--) {
        ll a, b;
        cin >> a >> b;
        if (a) cout << res[b] - res[a - 1] << endl;
        else cout << res[b] << endl;
    }
    return 0;
}
