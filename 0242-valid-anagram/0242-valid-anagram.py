class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        
        if len(s) != len(t):
            return False
        
        chrsS = {}
        chrsT = {}
        
        for i in range(len(s)):
            chrsS[s[i]] = 1 + chrsS.get(s[i], 0)
            chrsT[t[i]] = 1 + chrsT.get(t[i], 0)
            
        return chrsS == chrsT
        