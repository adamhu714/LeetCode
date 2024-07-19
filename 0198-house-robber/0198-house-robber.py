class Solution:
    def rob(self, nums: List[int]) -> int:
        maxRob = [0 for i in nums]
        rN = [nums[-1-i] for i in range(len(nums))]
        maxRob[0] = rN[0]
        if len(maxRob)> 1:
            maxRob[1] = max(rN[0], rN[1])
        for i in range(len(rN) - 2):
            maxRob[i+2] = max(rN[i+2] + maxRob[i], maxRob[i+1])
        return maxRob[-1]
        