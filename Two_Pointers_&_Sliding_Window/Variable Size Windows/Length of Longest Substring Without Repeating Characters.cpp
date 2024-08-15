// Variable Size Window

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main() {
    IO;
    string s;
    cin >> s;
    int i = 0, j = 0, mx = 0;
    unordered_set<char> st;
    while (i < s.size()) {
        while (j < s.size() && st.find(s[j]) == st.end()) {
            st.insert(s[j]);
            j++;
            mx = max(mx, j - i);
        }
        st.erase(s[i]);
        i++;
    }
    cout << mx << endl;
    return 0;
}

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main() {
    IO;
    string s;
    cin >> s;
    int i = 0, j = 0, mx = 0;
    unordered_set<char> st;
    while (j < s.size()) {
        if (st.find(s[j]) == st.end()) {
            st.insert(s[j]);
            j++;
            mx = max(mx, j - i);
        }
        else {
            st.erase(s[i]);
            i++;
        }
    }
    cout << mx << endl;
    return 0;
}

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main() {
    IO;
    string s;
    cin >> s;
    int i = 0, j = 0, mx = 0;
    set<char> st;
    while (j < s.size()) {
        int sz = st.size();
        st.insert(s[j]);
        j++;
        if (st.size() == sz) {
            while (s[i] != s[j - 1]) {
                auto itr = st.find(s[i]);
                st.erase(itr);
                i++;
            }
            auto itr = st.find(s[i]);
            st.erase(itr);
            i++;
        }
        mx = max(mx, j - i);
    }
    cout << mx << endl;
    return 0;
}
