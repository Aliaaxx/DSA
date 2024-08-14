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
    int i = 0, j = 0, sum = 0;
    while (i < n) {
        while (j < n && sum < target) {
            sum += arr[j];
            j++;
        }
        if (sum == target) {
            cout << i << " " << j - 1 << endl;
            return 0;
        }
        sum -= arr[i];
        i++;
    }
    cout <<  -1 << " " << -1 << endl;
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m), ans(m);
    for(int &i : a) cin >> i;
    for(int &i : b) cin >> i;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0, count = 0;
    while (j < m) {
        if (i == n) {
            ans[j] = count;
            j++;
        }
        else {
            if (a[i] < b[j]) {
                count += 1;
                i++;
            }
            else {
                ans[j] = count;
                j++;
            }
        }
    }
    
    for (int x : ans) {
        cout << x << " ";
    }
    return 0;
}
