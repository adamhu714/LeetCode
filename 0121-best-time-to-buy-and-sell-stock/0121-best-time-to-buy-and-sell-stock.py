class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        ans = 0
        l = 0
        r = 0
        while r < len(prices):
            ans = max(prices[r] - prices[l], ans)
            if prices[r] < prices[l]:
                l = r
            r = r + 1
        return ans