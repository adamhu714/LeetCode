class Solution:
    def findMin(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        l = 0
        r = len(nums) - 1
        while l < r:
            if nums[l//2 + r//2] > nums[-1]:
                l = l//2 + r//2 + 1
            else:
                r = l//2 + r//2
        return nums[l]