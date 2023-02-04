class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        
        diffs = {}
        for i in range(len(nums)):
            if target - nums[i] in diffs:
                return [diffs[target - nums[i]], i]
            else:
                diffs[nums[i]] = i