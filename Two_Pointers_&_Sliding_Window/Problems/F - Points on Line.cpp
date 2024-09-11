///*** https://codeforces.com/problemset/problem/251/A ***///

    #include <bits/stdc++.h>
    #define endl "\n"
    #define ll long long
    #define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
    using namespace std;

    ll noWays(int n) {
        return (n * 1ll * (n - 1)) / 2;
    }

    int main() {
        IO;
        int n, d;
        cin >> n >> d;
        vector<int> v(n);
        for (int &i : v) cin >> i;
        int l = 0, r = 1, sz;
        ll ans = 0;
        while (r < n) {
            while (v[r] - v[l] > d) {
                l++;
            }
            sz = r - l;
            ans += noWays(sz);
            r++;
        }
        cout << ans << endl;
        return 0;
    }
