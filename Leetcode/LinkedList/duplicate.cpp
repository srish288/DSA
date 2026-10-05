#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int>& nums) {

    // Step 1: Find meeting point
    int slow = nums[0];
    int fast = nums[0];

    do {
        slow = nums[slow];          // Move 1 step
        fast = nums[nums[fast]];    // Move 2 steps
    } while (slow != fast);

    // Step 2: Find cycle entrance
    slow = nums[0];

    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

int main() {

    int n;
    cin >> n;

    // n + 1 elements, values from 1 to n
    vector<int> nums(n + 1);

    for (int i = 0; i < n + 1; i++) {
        cin >> nums[i];
    }

    cout << findDuplicate(nums) << '\n';

    return 0;
}