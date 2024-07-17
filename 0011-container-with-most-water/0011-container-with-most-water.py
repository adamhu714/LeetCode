class Solution:
    def maxArea(self, height: List[int]) -> int:
        ans = 0
        l = 0
        r = len(height) - 1
        
        while l < r:
            ans = max(ans, (r - l)*min(height[l], height[r]))
            if height[l] > height[r]:
                r = r - 1
            else:
                l = l + 1
        return ans