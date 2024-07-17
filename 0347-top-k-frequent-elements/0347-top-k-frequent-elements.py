class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = {}
        bucket = [[] for i in range(len(nums)+1)]
        
        for num in nums:
            freq[num] = freq.get(num, 0) + 1
        
        for key in freq:
            bucket[freq[key]].append(key)
            
        i = len(nums)
        ans = []
        count = 0
        while count < k:
            i -= 1
            ans.extend(bucket[i])
            count += len(bucket[i])
        
        return ans