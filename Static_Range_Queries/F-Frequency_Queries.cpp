///*** https://www.hackerrank.com/challenges/frequency-queries/problem ***///

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main() {
    IO;
    ll q;
    cin >> q;
    map<ll, ll> mp, freq;
    while (q--) {
        ll n, m;
        cin >> n >> m;
        if (n == 1) { //insert
            int val = mp[m];
            freq[val]--;
            mp[m]++;
            freq[mp[m]]++;
        }
        else if (n == 2) { //delete
            if (mp[m] > 0) {
                freq[mp[m]]--;
                mp[m]--;
                freq[mp[m]]++;
            }
        }
        else { // check freq z
            if (freq[m] > 0) cout << "1" << endl;
            else cout << "0" << endl;
        }
    }
    return 0;
}
