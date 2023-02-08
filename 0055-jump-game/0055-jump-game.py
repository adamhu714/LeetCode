class Solution:
    def canJump(self, nums: List[int]) -> bool:
        '''
        Function checks if you are able to reach the last index of the given array.
        '''
        reachable = 0
        for i in range(len(nums)):
            if i > reachable:
                return False
            reachable = max([i + nums[i], reachable])
        return True