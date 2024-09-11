///*** https://codeforces.com/problemset/problem/372/A ***///

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main() {
    IO;
    int n;
    cin >> n;
    vector<int> kangaroos(n);
    for (int &i : kangaroos) cin >> i;
    sort(kangaroos.begin(), kangaroos.end());
    int l = 0, r = n / 2, hidden = 0;
    while (l < n / 2 and r < n) {
        if (kangaroos[r] >= kangaroos[l] * 2) {
            l++;
            hidden++;
        }
        r++;
    }
    cout << n - hidden << endl;
    return 0;
}
