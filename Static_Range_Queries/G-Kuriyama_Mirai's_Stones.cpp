///*** https://codeforces.com/problemset/problem/433/B ***///

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
 
int main() {
    IO;
    ll n;
    cin >> n;
    vector<ll> v(n), preSum(n), ord_preSum(n);
    for (ll &i : v) {
        cin >> i;
    }
    preSum[0] = v[0];
    for (ll i = 1; i < n; ++i) {
        preSum[i] = (preSum[i - 1] + v[i]);
    }
    sort(v.begin(), v.end());
    ord_preSum[0] = v[0];
    for (ll i = 1; i < n; ++i) {
        ord_preSum[i] = (ord_preSum[i - 1] + v[i]);
    }
    ll q;
    cin >> q;
    while (q--) {
        ll type, l, r;
        cin >> type >> l >> r;
        if (type == 1) {
            if (l != 1) cout << preSum[r - 1] - preSum[l - 2] << endl;
            else cout << preSum[r - 1] << endl;
        }
        else {
            if (l != 1) cout << ord_preSum[r - 1] - ord_preSum[l - 2] << endl;
            else cout << ord_preSum[r - 1] << endl;
        }
    }
    return 0;
}
