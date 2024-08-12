///*** https://codeforces.com/contest/296/problem/C ***///

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
 
int main() {
    IO;
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> arr(n);
    for (ll &i : arr) {
        cin >> i;
    }
    vector<vector<ll>> op(m, vector<ll>(3));
    for (ll i = 0; i < m; i++) {
        ll l, r, d;
        cin >> l >> r >> d;
        op[i] = {l - 1, r - 1, d};
    }
    vector<ll> freq(m + 1);
    while (k--) {
        ll x, y;
        cin >> x >> y;
        freq[x - 1] += 1;
        freq[y] -= 1;
    }
    for (ll i = 1; i < m + 1; i++) {
        freq[i] += freq[i - 1];
    }
    vector<ll> parSum(n + 1);
    for (ll i = 0; i < m; i++) {
        ll f = freq[i], L = op[i][0], R = op[i][1], D = op[i][2] * f;
        parSum[L] += D;
        parSum[R + 1] -= D;
    }
    for (ll i = 1; i < n; i++) {
        parSum[i] += parSum[i - 1];
    }
    for (ll i = 0; i < n; i++) {
        parSum[i] += arr[i];
        cout << parSum[i] << " ";
    }
    return 0;
}
