// Foundational Problem
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main() {
    IO;
    int n, target;
    cin >> n >> target;
    vector<int> arr(n);
    for(int &i : arr) {
        cin >> i;
    }
    int l = 0, r = n - 1;
    while (l < r) {
        int sum = arr[l] + arr[r];
        if (sum > target) {
            r--;
        }
        else if (sum < target) {
            l++;
        }
        else {
            cout << arr[l] << " " << arr[r] << endl;
            break;
        }
    }
    return 0;
}
