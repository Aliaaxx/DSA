///*** https://codeforces.com/problemset/problem/474/B ***///

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
 
int main() {
    IO;
    int n, m;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr) cin >> i;
    cin >> m;
    vector<int> v(m);
    for (int &i : v) cin >> i;
    vector<int> preSum(n);
    preSum[0] = arr[0];
    for (int i = 1; i < n; i++) {
        preSum[i] = preSum[i - 1] + arr[i];
    }
    for (int t : v) {
        int l = 0, r = n -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (t <= preSum[mid]) {
                if (mid) {
                    if (t > preSum[mid - 1]) {
                        cout << mid + 1 << endl;
                        break;
                    }
                    else {
                        r = mid - 1;
                    }
                }
                else {
                    cout << mid + 1 << endl;
                    break;
                }
            }
            else { // t > preSum[mid]
                l = mid + 1;
            }
        }
    }
    return 0;
}
