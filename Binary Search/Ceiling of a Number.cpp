// You have an array and a Number
// get the first number from the array that is equal to or larger that the given number

int ceiling (vector<int> arr, int target) {
    if (target > arr[arr.size() - 1]) {
        return -1;
    }
    int start = 0, end = arr.size() - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] > target) {
            end = mid - 1;
        }
        else if (arr[mid] < target) {
            start = mid + 1;
        }
        else {
            return mid;
        }
    }
    return start;
}

/////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main() {
    IO;
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &i : arr) cin >> i;
    int t;
    cin >> t;
    int idx;
    if (target > arr[n - 1]) {
        idx = -1;
    }
    else {
        idx = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
    }
    cout << idx << endl;
    return 0;
}
