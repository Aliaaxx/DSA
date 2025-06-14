#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

vector<int> nums = {1, 2, 0, 2};
int trgt = 4;
vector<int> ans;

void solve(int i, int sum) {
    // invalid state  
    if (sum > trgt) {
        return;
    }
  
    if (sum == trgt) {
        for (int &n : ans){
            cout<< n << " ";
        }
        cout << endl;
        return;
    }
    if (i == nums.size()) {
        return;
    }

    // options
    ans.push_back(nums[i]);
    solve(i + 1, sum + nums[i]);
    ans.pop_back();
    solve(i + 1, sum);
}
int main() {
    IO;
    solve(0, 0);
    return 0;
}
