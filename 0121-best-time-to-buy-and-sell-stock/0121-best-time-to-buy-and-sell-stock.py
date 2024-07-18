class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        ans = 0
        low = prices[0]
        r = 0
        while r < len(prices):
            ans = max(prices[r] - low, ans)
            if prices[r] < low:
                low = prices[r]
            r = r + 1
        return ans