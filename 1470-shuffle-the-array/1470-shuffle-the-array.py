class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        newArray = [0]*(2*n)
        for i in range(0, n):
            j = 2*i
            newArray[j] = nums[i]
            newArray[j+1] = nums[i+n]
        return newArray