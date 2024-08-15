// Variable Size Window

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
    for (int &x : arr) cin >> x;
    int i = 0, j = 0, sum = 0, count = 0;
    while (i < n) {
        while (j < n && sum < target) {
            sum += arr[j];
            j++;
        }
        if (sum == target) {
            cout << i << " " << j - 1 << endl;
            count += 1;
        }
        sum -= arr[i];
        i++;
    }
    cout << count << endl;
    return 0;
}
