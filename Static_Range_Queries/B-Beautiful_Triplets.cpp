///*** https://www.hackerrank.com/contests/world-codesprint-april/challenges/beautiful-triplets ***///

//Third Submission

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

const int Max = 1e5 + 5;
int after[Max], before[Max];

int main() {
    IO;
    int n, d;
    cin >> n >> d;
    vector<int> v(n);
    for (int &i : v) {
        cin >> i;
        after[i]++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int aj = v[i];
        after[aj]--;
        if (aj - d >= 0 and after[aj + d] > 0 and before[aj - d] > 0) {
            ans += after[aj + d] * before[aj - d]; //kol tkrar leh answer
        }
        before[aj]++;
    }
    cout << ans << endl;
    return 0;
}


// Second submission

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main() {
    IO;
    int n, d;
    cin >> n >> d;
    vector<int> v(n);
    for (int &i : v) cin >> i;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (find(v.begin(), v.end(),v[i] + d) != v.end() and find(v.begin(), v.end(),v[i] + 2 * d) != v.end()) {
            ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}


// First Submission

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main() {
    IO;
    int n, d;
    cin >> n >> d;
    vector<int> v(n);
    for (int &i : v) cin >> i;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[j] - v[i] != d) continue;
            for (int k = j + 1; k < n; k++) {
                if (v[k] - v[j] == d) {
                    ans += 1;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
