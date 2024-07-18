class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        ans = 0
        low = prices[0]
        for p in prices:
            ans = max(p - low, ans)
            if p < low:
                low = p
        return ans