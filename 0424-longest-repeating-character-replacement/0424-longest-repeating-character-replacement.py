class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        freq = {}
        l = 0
        maxf = 0
        for r in range(len(s)):
            freq[s[r]] = freq.get(s[r], 0) + 1
            maxf = max(maxf, freq[s[r]])
            if r - l + 1 > maxf + k:
                freq[s[l]] = freq[s[l]] - 1
                l = l + 1
        return r - l + 1