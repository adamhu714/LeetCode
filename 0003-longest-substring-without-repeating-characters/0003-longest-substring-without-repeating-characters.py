class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        sub = ""
        ans = 0
        for c in s:
            while c in sub:
                sub = sub[1:]
            sub = sub + c
            ans = max(ans, len(sub))
        return ans