class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        
        unordered_map<int, int> mp;
        int maxVal = * max_element(nums.begin(), nums.end());
        int minVal = * min_element(nums.begin(), nums.end());
        for (auto i : nums) {
            ++mp[i];
        }
        
        int j = 0;
        
        for (int i = minVal; i <= maxVal; ++i) {
            while (mp.find(i) != mp.end() && mp[i] > 0) {
                nums[j] = i;
                --mp[i];
                ++j;
            }
        }
        return nums;
    }
};