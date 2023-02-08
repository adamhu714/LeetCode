class Solution:
    def jump(self, nums: List[int]) -> int:
        
        reached = 0
        oldReach = 0
        jumps = 0
        
        for i in range(len(nums) - 1):
            
            reached = max(reached, i + nums[i])
            
            if reached >= len(nums) - 1:
                return jumps + 1
            if i == oldReach:
                oldReach = reached
                jumps +=1
            
        return jumps