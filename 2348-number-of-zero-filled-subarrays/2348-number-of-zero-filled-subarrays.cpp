class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int lenOfZ = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                ++lenOfZ;
                ans += lenOfZ;
            } else {
                lenOfZ = 0;
            }
        }
        return ans;
    }
};