class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        // sorted, therefore know that before target, 2n and 2n+1 index should be same
        // also, 2n-1 should be different to 2n 
        
        if (nums.size() > 1  && nums[0] != nums[1]) {
            return nums[0];
        }
        
        int start = 0;
        int end = nums.size() - 1;
        int mid = 0;
        while (start != end) {
            mid = ((start + end) / 2) - ((start + end) / 2) % 2;
            if (nums[mid] == nums[mid + 1]) {
                start = mid + 2;
            } else if (nums[mid] == nums[mid-1]) {
                end = mid - 2;
            } else {
                return nums[mid];
            }
        }
        return nums[start];
    }
};