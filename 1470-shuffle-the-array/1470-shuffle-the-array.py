class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        idx = 0
        newArray = [0]*(2*n)
        newArray[0] = nums[0]
        for i in range(1, 2*n):
            if i % 2 == 1:
                idx += n
            else:
                idx -= n - 1
            newArray[i] = nums[idx]
        return newArray