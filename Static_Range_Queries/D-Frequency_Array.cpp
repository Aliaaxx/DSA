///*** https://www.codechef.com/problems/FREQARRY ***///

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

const int Max = 1e5 + 5;
int freq[Max];

int main() {
    IO;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n), preSum(n);
        for (int &i : v) {
            cin >> i;
            freq[i]++;
        }
        sort(freq, freq+Max, greater<int> ());
        if (freq[0] > 1) cout << "ne krasivo" << endl;
        else cout << "prekrasnyy" << endl;
    }
    return 0;
}
