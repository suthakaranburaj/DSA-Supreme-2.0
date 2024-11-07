#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dp;
    vector<int> ans;

    for (int i = 0; i < k; i++) {
        int element = nums[i];
        while (!dp.empty() && element > nums[dp.back()]) {
            dp.pop_back();
        }
        dp.push_back(i);
    }

    for (int i = k; i < nums.size(); i++) {
        ans.push_back(nums[dp.front()]);

        int element = nums[i];
        if (!dp.empty() && i - dp.front() >= k) {
            dp.pop_front();
        }
        while (!dp.empty() && element > nums[dp.back()]) {
            dp.pop_back();
        }
        dp.push_back(i);
    }

    ans.push_back(nums[dp.front()]);

    return ans;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> ans = maxSlidingWindow(nums, k);
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
