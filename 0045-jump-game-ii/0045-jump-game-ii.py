class Solution:
    def jump(self, nums: List[int]) -> int:
        # want to return minimum number of jumps required
        # know that we can reach the end, which means every index is reachable
        # want to start from the beginning of the list, and exhaust every n jump route before looking at n+1 to prevent 
        # redundant calculations 
        # keep track of highest number reachable at every jump
        
        reached = nums[0]
        checked = 0
        jumps = 1
        while len(nums) > 2 and reached < len(nums) - 1:
            for i in range(reached, checked, -1):
                reached = max(reached, i + nums[i])
                if reached >= len(nums) - 1:
                    return jumps + 1
                checked = i
                print(i, reached)
            jumps += 1
        return min(len(nums) - 1, jumps)