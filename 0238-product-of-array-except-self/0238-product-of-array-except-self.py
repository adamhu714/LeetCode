class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        
        ans = [1 for num in nums]
        
        for i in range(len(nums) - 1):
            ans[i+1] = ans[i] * nums[i]
        
        post = 1
        for i in range(len(nums)-1, 0, -1):
            post *= nums[i]
            ans[i-1] *= post
        return ans