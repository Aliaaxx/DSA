///*** https://codeforces.com/gym/102397/problem/E ***///

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main() {
    IO;
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int &i : v) cin >> i;
    int i = 0, j = 0, cnt = 0, mn = INT_MAX;
    while (i < n) {
        while (j < n and cnt < k) {
            cnt += v[j];
            j++;
        }
        if (cnt >= k) {
            mn = min(mn, j - i);
        }
        cnt -= v[i];
        i++;
    }
    cout << (mn != INT_MAX ? mn : -1) << endl;
    return 0;
}
