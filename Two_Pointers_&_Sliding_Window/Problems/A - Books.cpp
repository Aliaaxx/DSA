///*** https://codeforces.com/problemset/problem/279/B ***///

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
 
int main() {
    IO;
    int n, t;
    cin >> n >> t;
    vector<int> v(n);
    for (int &i : v) cin >> i;
    int i = 0, j = 0, sz = t, mx = 0;
    while (i < n) {
        while (j < n and sz - v[j] >= 0) {
            sz -= v[j];
            j++;
        }
        mx = max(mx, j - i);
        sz += v[i];
        i++;
    }
    cout << mx << endl;
    return 0;
}
