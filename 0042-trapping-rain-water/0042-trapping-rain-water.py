class Solution:
    def trap(self, height: List[int]) -> int:
        maxL = height[0]
        maxR = height[-1]
        l = 0
        r = len(height) - 1
        ans = 0
        while l < r:
            if maxL < maxR:
                l = l + 1
                ans = ans + max(0, maxL - height[l])
                maxL = max(maxL, height[l])
            else:
                r = r - 1
                ans = ans + max(0, maxR - height[r])
                maxR = max(maxR, height[r])
                
        return ans