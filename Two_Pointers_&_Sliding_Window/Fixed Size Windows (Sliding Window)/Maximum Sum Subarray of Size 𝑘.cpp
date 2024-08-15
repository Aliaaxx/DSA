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
    for (int &i : arr) cin >> i;
    int i = 0, j = 0, sum = 0, mx = 0;
    while (i < n) {
        while (j < n && j - i < k) {
            sum += arr[j];
            j++;
        }
        mx = max(sum, mx);
        sum -= arr[i];
        i++;
    }
    cout << mx << endl;
    return 0;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

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
    for (int &i : arr) cin >> i;
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += arr[i];
    }
    int l = 1, r = k, mx = sum;
    while (r < n) {
        sum -= arr[l - 1];
        sum += arr[r];
        mx = max(mx, sum);
        l++, r++;
    }
    cout << mx << endl;
    return 0;
}
