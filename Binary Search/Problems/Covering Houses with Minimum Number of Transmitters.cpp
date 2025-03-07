///*** hackerrank.com/challenges/hackerland-radio-transmitters/problem?isFullScreen=true ***///
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main() {
    IO;
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int& i : arr) cin >> i;
    sort(arr, arr + n);
    auto ok = [&](int num) {
        // check if the num which is the number of radios with k range will cover all the houses;
        int i = 0;
        int numUsed = 0;
        while (i < n) {
            int rangeCovered = arr[i] + k;
            while (i < n and arr[i] <= rangeCovered) {
                i++;
            }
            numUsed += 1;
            if (numUsed > num) return false;
            int lastCovered = arr[i - 1] + k;
            while(i < n and arr[i] <= lastCovered) {
                i++;
            }
        }
        return true;
    };
    int start = 1, end = 1e6, res;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (ok(mid)) {
            res = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    cout << res;
    return 0;
}
