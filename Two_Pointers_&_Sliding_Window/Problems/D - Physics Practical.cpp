///*** https://codeforces.com/contest/253/problem/B ***///
// Dynamic Window

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
 
int main() {
    IO;
    ifstream Cin ("input.txt");
    ofstream Cout ("output.txt");
    int n;
    Cin >> n;
    vector<int> v(n);
    for(int &i: v) Cin >> i;
    sort(v.begin(), v.end());
    int i =0, j =0, mn = INT_MAX;
    while (i < n) {
        while (j < n and v[j] <= v[i] * 2) {
            j++;
        }
        int cmp = n - (j - i);
        mn = min(mn, cmp);
        if (j == n and v[i] * 2 >= v[j]) {
            break;
        }
        i++;
    }
    Cout << mn << endl;
    return 0;
}
