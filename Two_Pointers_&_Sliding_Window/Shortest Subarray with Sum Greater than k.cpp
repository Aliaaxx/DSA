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
    //expand till the sum exceeds k then contract to minimize the length of the subarray
    int i = 0, j = 0, sum = 0, mn = INT_MAX;
    while (j < n) {
        sum += arr[j];
        j++;
        while (sum > k) {
            mn = min(mn, j - i);
            sum -= arr[i];
            i--;
        }
    }
    cout << (mn != INT_MAX ? mn : -1) << endl;
    return 0;
}
