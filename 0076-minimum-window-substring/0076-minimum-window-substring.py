class Solution:
    def minWindow(self, s: str, t: str) -> str:
        l = 0
        ans = ""
        ansL = float("infinity")
        freqT = {}
        freqS = {}
        count = 0
        
        for c in t:
            freqT[c] = freqT.get(c, 0) + 1
        
        for r in range(len(s)):
            freqS[s[r]] = freqS.get(s[r], 0) + 1
            if s[r] in freqT and freqS[s[r]] == freqT[s[r]]:
                count = count + 1
            while count == len(freqT) and l < r + 1:
                if r - l + 1 < ansL:
                    ansL = r - l + 1
                    ans = s[l:r+1]
                freqS[s[l]] = freqS[s[l]] - 1
                if s[l] in freqT and freqS[s[l]] < freqT[s[l]]:
                    count = count - 1
                l = l + 1
        return ans