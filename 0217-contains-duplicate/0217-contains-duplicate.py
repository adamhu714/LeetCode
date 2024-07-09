class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        hashset = set()
        for num in nums:
            hashset.add(num)
        return len(hashset) != len(nums)