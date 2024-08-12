///*** https://codeforces.com/problemset/problem/363/B ***///

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
 
int main() {
    IO;
    ll n, k;
    cin >> n >> k;
    vector<int> v(n), preSum(n);
    map<int, int> mp; // sum, idx
    for (int &i : v) {
        cin >> i;
    }
    preSum[0] = v[0];
    for (int i = 1; i < n; i++) {
        preSum[i] += (v[i] + preSum[i - 1]);
    }
    int wd = k - 1;
    mp[preSum[k - 1]] = 1;
    for (int i = 1; i <= n - k; i++) {
        mp[preSum[i + (k - 1)] - preSum[i - 1]] = i + 1;
    }
    for (auto[a, b] : mp) {
        cout << b << endl;
        break;
    }
    return 0;
}
