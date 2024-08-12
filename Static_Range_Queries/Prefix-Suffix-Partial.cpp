#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

const int Max = 1e6 + 5;
int freq[Max];

int main() {
    IO;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int l, r;
    cin >> l >> r;


///*** Prefix Sum Array ***///

    vector<int> prefix(n);
    for (int i = 0; i < n; ++i) {
        prefix[i] = arr[i];
        if (i) prefix[i] += prefix[i - 1];
    }
    for (int i : prefix) {
        cout << i << " ";
    }
    cout << endl;


///*** Suffix Sum Array ***///
  
    vector<int> suffix(n);
    suffix[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suffix[i] = arr[i] + suffix[i + 1];
    }
    for (int i : suffix) {
        cout << i << " ";
    }
    cout << endl;


///*** Range Sum using prefix Array ***///

    int ans = prefix[r];
    if (l > 0) ans -= prefix[l - 1]; // zero based
    cout << ans << endl;


///*** Range Sum using Suffix Array ***///
  
    int anss = suffix[l];
    if (r < n - 1) anss -= suffix[r + 1]; // zero based
    cout << anss << endl;


///*** Prefix Minimum Array ***///
  
    vector<int> preMin(n);
    preMin[0] = arr[0];
    for (int i = 1; i < n; i++) {
        preMin[i] = min(arr[i], preMin[i - 1]);
    }
    for (int i : preMin) {
        cout << i << " ";
    }
    cout << endl;


///*** Suffix Minimum Array ***///
  
    vector<int> sufMin(n);
    sufMin[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        sufMin[i] = min(arr[i], sufMin[i + 1]);
    }
    for (int i : sufMin) {
        cout << i << " ";
    }
    cout << endl;
    

///*** Partial Sum ***///

    int m;
    cin >> m;
    vector<int> a(m);
    for (int &i : a) cin >> i;
    int q;
    cin >> q;
    vector<int> d(m + 1);
    while (q--) {
        int  l, r, val;
        cin >> l >> r >> val;
        d[l] += val;
        d[r + 1] -= val;
    }
    a[0] += d[0];
    for (int i = 1; i < m; i++) {
        d[i] += d[i - 1];
        a[i] += d[i];
    }
    for (int i : a) cout << i << " ";
    return 0;
}
