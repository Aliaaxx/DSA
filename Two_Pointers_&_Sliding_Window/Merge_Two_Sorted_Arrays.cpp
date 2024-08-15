// Foundational Problem

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main() {
    IO;
    int n, m;
    cin >> n >> m;
    vector<int> arr1(n), arr2(m), merged_arr(n + m);
    for(int &i : arr1) cin >> i;
    for(int &i : arr2) cin >> i;

    int i = 0, j = 0;
    for (int idx = 0; idx < merged_arr.size(); idx++) {
        if (i == n) {
            merged_arr[idx] = arr2[j];
            j++;
        }
        else if (j == m) {
            merged_arr[idx] = arr1[i];
            i++;
        }
        else if (arr1[i] <= arr2[j]) {
            merged_arr[idx] = arr1[i];
            i++;
        }
        else {
            merged_arr[idx] = arr2[j];
            j++;
        }
    }

    for (int x : merged_arr) {
        cout << x << " ";
    }
    return 0;
}

/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;


int main() {
    IO;
    int n, m;
    cin >> n >> m;
    vector<int> arr1(n), arr2(m), merged_arr(n + m);
    for(int &i : arr1) cin >> i;
    for(int &i : arr2) cin >> i;

    int i = 0, j = 0, idx = 0;
    while (i < n && j < m) {
        if (arr1[i] <= arr2[j]) {
            merged_arr[idx] = arr1[i];
            i++;
        }
        else {
            merged_arr[idx] = arr2[j];
            j++;
        }
        idx++;
    }
    // will enter one of those only
    while(i < n) {
        merged_arr[idx] = arr1[i];
        i++;
        idx++;
    }
    while (j < m) {
        merged_arr[idx] = arr2[j];
        j++;
        idx++;
    }
    
    for (int x : merged_arr) {
        cout << x << " ";
    }
    return 0;
}
