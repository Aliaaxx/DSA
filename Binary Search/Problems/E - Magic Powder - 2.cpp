///*** https://codeforces.com/problemset/problem/670/D2 ***///

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
 
int main() {
    IO;
    ll n, magicPowder;
    cin >> n >> magicPowder;
    ll needed[n], have[n];
    for (ll &i : needed) cin >> i;
    for (ll &i : have) cin >> i;
 
    auto check = [&](ll num_cookies) {
        ll powder = magicPowder;
        for (ll i = 0; i < n; ++i) {
            ll need = needed[i] * num_cookies;
            if (have[i] < need) {
                if (powder >= (need - have[i])) {
                    powder -= (need - have[i]);
                }
                else {
                    return false;
                }
            }
        }
        return true;
    };
 
    // Binary Search on Answer
    ll start = 0, end = 3e9, res;
    while (start <= end) {
        ll mid = start + (end - start) / 2;
        if (check(mid)) {
            start = mid + 1;
            res = mid;
        }
        else {
            end = mid - 1;
        }
    }
    cout << res << endl;
    return 0;
}
