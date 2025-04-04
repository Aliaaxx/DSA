///*** https://www.hackerrank.com/contests/101hack39/challenges/equality-in-a-array ***///

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main() {
    IO;
    int n;
    cin >> n;
    vector<int> v(n), freq(105);
    for (int &i : v) {
        cin >> i;
        freq[i]++;
    }
    sort(freq.rbegin(), freq.rend());
    cout << n - freq[0] << endl;
    return 0;
}
