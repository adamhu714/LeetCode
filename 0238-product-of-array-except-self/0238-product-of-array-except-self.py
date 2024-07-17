class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        
        answer = [1 for num in nums]
        
        pre = 1
        post = 1
        for i in range(len(nums) - 1):
            pre = pre * nums[i]
            answer[i+1] *= pre
            post = post * nums[-1 -i]
            answer[-2 - i] *= post
        
        return answer