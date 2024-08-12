///*** https://codeforces.com/problemset/problem/961/B ***///

// Second Submission

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
 
int main() {
    IO;
    int n, k;
    cin >> n >> k;
    vector<int> arr(n), preSum(n);
    for (int &i : arr) {
        cin >> i;
    }
    int val = 0;
    for (int i = 0, t; i < n; ++i) {
        cin >> t;
        if (t) {
            val += arr[i];
            arr[i] = 0;
        }
    }
    partial_sum(arr.begin(), arr.end(), arr.begin());
    int l = 0, r = k - 1;
    int mx = 0;
    while (r <= n - 1) {
        int sum;
        if (l) sum = arr[r] - arr[l - 1];
        else sum = arr[r];
        mx = max(sum, mx);
        l++, r++;
    }
    cout << val + mx << endl;
    return 0;
}


// First Submission

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
 
int main() {
    IO;
    int n, k;
    cin >> n >> k;
    vector<int> arr(n), t(n), preSum(n);
    for (int &i : arr) {
        cin >> i;
    }
    for (int &i : t) {
        cin >> i;
    }
    int val = 0;
    for (int i = 0; i < n; i++) {
        if(t[i] == 1) {
            val += arr[i];
            arr[i] = 0;
        }
    }
    preSum[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        preSum[i] = (preSum[i - 1] + arr[i]);
    }
    map<int, int> mp;
    mp[preSum[k - 1]] = 0;
    for (int i = 1; i <= n - k; i++) {
        mp[preSum[i + k - 1] - preSum[i - 1]] = i;
    }
    for (auto itr = mp.rbegin(); itr != mp.rend(); itr++) {
        val += itr->first;
        break;
    }
    cout << val << endl;
    return 0;
}
