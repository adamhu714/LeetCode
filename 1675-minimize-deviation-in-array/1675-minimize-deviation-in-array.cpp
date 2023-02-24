class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        
        int minN = INT_MAX;
        int res = INT_MAX;
        
        for (int& n : nums) {
            n = n % 2 ? n *= 2 : n;
            minN = min(minN, n);
        }
        
        make_heap(nums.begin(), nums.end());
        
        while (nums[0] % 2 == 0) {
            res = min(res, nums[0] - minN);
            minN = min(minN, nums[0]/2);
            pop_heap(nums.begin(), nums.end());
            nums.back()/=2;
            push_heap(nums.begin(), nums.end());
        }
        return min(res, nums[0] - minN);
    }
};