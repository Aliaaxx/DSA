// You have an array and a Number
// get the first number from the array that is equal to or smaller than the given number

int floor (vector<int> arr, int target) {
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
    return end;

///////////////////////////////////////////////////////////////////////////////

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
    int target;
    cin >> target;
    int idx = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
    if (idx) cout << idx - 1;
    else cout << idx;
    return 0;
}
