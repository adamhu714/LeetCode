class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int start, int end){
        if (start > end) {
            return (start < nums.size() && nums[start] < target) ? start + 1: start;
        }
        
        int mid = (end + start) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        return (nums[mid] > target) ? binarySearch(nums, target, start, mid - 1) : binarySearch(nums, target, mid + 1, end);
    }
    
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }
};