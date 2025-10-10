#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

const int sz = 1000;
int mem[sz];
int fib(int n) {
    if (n <= 1) {
        return n;
    }
    auto &ret = mem[n];
    if (~ret) return ret;
    return ret = fib(n - 1) + fib(n - 2);
}

int main() {
    IO;
    int n;
    cin >> n;
    memset(mem, -1, sizeof(mem));
    cout << fib(n);
    return 0;
}
