class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS(1, nums[0]);
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i] > LIS.back()) {
                LIS.push_back(nums[i]);
            } else {
                // binary search
                int start = 0, end = LIS.size() - 1, mid;
                while (start < end) {
                    mid = (start + end)/2;
                    if (LIS[mid] >= nums[i]) {
                        end = mid;
                    } else {
                        start = mid + 1;
                    }
                }
                if (LIS[start] > nums[i]) {
                    LIS[start] = nums[i];
                }
            }
        }
        return LIS.size();
    }
};

// dynamic programming:
// time O(n^2)
// space O(n)
        // int n = nums.size();
        // vector<int> dp(n, 1);
        // int maxVal = 1;
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < i; ++j) {
        //         if (nums[j] < nums[i]) {
        //             dp[i] = max(dp[i], dp[j] + 1);
        //             maxVal = max(maxVal, dp[i]);
        //         }
        //     }
        // }
        // return maxVal;