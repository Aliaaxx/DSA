// Variable Size Window

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main() {
    IO;
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;
    int i = 0, j = 0, sum = 0, mx = 0;
    while (i < n) {
        while (j < n && sum + arr[j] <= k) {
            sum += arr[j];
            j++;
        }
        mx = max(mx, j - i);
        sum -= arr[i];
        i++;
    }
    cout << mx << endl;
    return 0;
}
