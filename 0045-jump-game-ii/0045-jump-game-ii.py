class Solution:
    def jump(self, nums: List[int]) -> int:
        # want to return minimum number of jumps required
        # know that we can reach the end, which means every index is reachable
        # want to start from the beginning of the list, and exhaust every n jump route before looking at n+1 to prevent 
        # redundant calculations 
        # keep track of highest number reachable at every jump
        
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