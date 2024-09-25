///*** https://codeforces.com/problemset/problem/600/B ***///

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
 
int main() {
    IO;
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;
    sort (a.begin(), a.end());
    for (int i : b) {
        auto ans = upper_bound(a.begin(), a.end(), i) - a.begin();
        cout << ans << " ";
    }
    return 0;
}
