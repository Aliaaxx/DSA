///*** https://codeforces.com/problemset/problem/381/A ***///

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
 
int main() {
    IO;
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i : v) cin >> i;
    int i = 0, j = n - 1, sr = 0, Di = 0;
    bool ord = true;
    while (i <= j) {
        if (v[i] >= v[j]) {
            if (ord) sr += v[i];
            else Di += v[i];
            i++;
        }
        else {
            if (ord) sr += v[j];
            else Di += v[j];
            j--;
        }
        ord = !ord;
    }
    cout << sr << " " << Di << endl;
    return 0;
}
