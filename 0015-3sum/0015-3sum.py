class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ans = []
        nums.sort()
        
        for i, a in enumerate(nums):
            if a > 0:
                break
            
            if i > 0 and a == nums[i - 1]:
                continue
            
            l = i + 1
            r = len(nums) - 1
            
            while l < r:
                sum = a + nums[l] + nums[r]
                if sum == 0:
                    ans.append([a, nums[l], nums[r]])
                    l = l + 1
                    while l < r and nums[l] == nums[l - 1]:
                        l = l + 1
                elif sum < 0:
                    l = l + 1
                else:
                    r = r - 1
        
        return ans