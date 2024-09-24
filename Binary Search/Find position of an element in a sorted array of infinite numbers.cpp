#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

// find the start and end
// optimize how you going to find start and end
// Double the Size you are searching in it
// Down to up instead of up to down so they are the same -> log n

int binarySearch_infiniteArray(vector<int> arr, int target, int start, int end) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] < target) {
            start = mid + 1;
        }
        else if (arr[mid] > target) {
            end = mid - 1;
        }
        else {
            return mid;
        }
    }
    return -1;
}

int answer(vector<int> arr, int target) {
    // Findinf the Range
    // start with the box of size 2
    int start = 0, end = 1;

    // condition for the target to lie in the range
    // double the size
    while (target > arr[end]) {
        int box_size = (end - start + 1);
        start = end + 1;
        end = end + box_size * 2;
    }
    return binarySearch_infiniteArray(arr, target, start, end);
}

int main() {
    IO;
    vector<int> nums = {2, 2, 5, 6, 7, 8, 9, 15 ,30};
    int target = 3;
    cout << answer(nums, target) << endl;
    return 0;
}
