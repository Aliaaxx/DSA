///*** https://codeforces.com/problemset/problem/670/D1 ***///

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main() {
    IO;
    int n, magicPowder;
    cin >> n >> magicPowder;
    int needed[n], have[n];
    for (int &i : needed) cin >> i;
    for (int &i : have) cin >> i;
    auto check = [&](int num_cookies) {
        int powder = magicPowder;
        for (int i = 0; i < n; ++i) {
            int need = needed[i] * num_cookies;
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
    int start = 0, end = 2000, res;
    while (start <= end) {
        int mid = (start + end) / 2;
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
