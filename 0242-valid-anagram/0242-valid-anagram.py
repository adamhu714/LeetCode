class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        
        if len(s) != len(t):
            return False
        
        chrsS = {}
        chrsT = {}

        
        for i in range(len(s)):
            
            if s[i] in chrsS:
                chrsS[s[i]] += 1
            else:
                chrsS[s[i]] = 1
                
            if t[i] in chrsT:
                chrsT[t[i]] += 1
            else:
                chrsT[t[i]] = 1
                
        return chrsS == chrsT