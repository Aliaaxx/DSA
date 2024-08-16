#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main() {
    IO;
    int n, k;
    cin >> n >> k;
    vector<int> arr(n), ans;
    for (int &i : arr) cin >> i;
    priority_queue<pair<int, int>> pq;
    int i = 0, j = 0;
    while (i < n) {
        while (j < n && j - i < k) {
            pq.emplace(arr[j], j);
            j++;
        }
        while (pq.top().second < i || pq.top().second > j) {
            pq.pop();
        }
        ans.push_back(pq.top().first);
        i++;
        if (j == n) break;
    }
    for (int x : ans) cout << x << " ";
    return 0;
}

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main() {
    IO;
    int n, k;
    cin >> n >> k;
    vector<int> arr(n), ans;
    for (int &i : arr) cin >> i;
    priority_queue<pair<int, int>> pq;
    for (int i  = 0; i < k; i++) {
        pq.emplace(arr[i], i);
    }
    ans.push_back(pq.top().first);
    for (int i = k; i < n; i++) {
        pq.emplace(arr[i], i);
        while (pq.top().second <= i - k) {
            pq.pop();
        }
        ans.push_back(pq.top().first);
    }
    for (int x : ans) cout << x << " ";
    return 0;
}
