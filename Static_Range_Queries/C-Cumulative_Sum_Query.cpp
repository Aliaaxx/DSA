///*** https://www.spoj.com/problems/CSUMQ/ ***///

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
 
int main() {
    IO;
    int n, d;
    cin >> n;
    vector<int> v(n), preSum(n);
    for (int &i : v) cin >> i;
    preSum[0] = v[0];
    for (int i = 1; i < n; i++) {
        preSum[i] += (preSum[i-1] + v[i]);
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (l) cout << preSum[r] - preSum[l - 1] << endl;
        else cout << preSum[r] << endl;
    }
    return 0;
} 
