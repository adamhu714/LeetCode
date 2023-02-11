class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        
        if len(s) != len(t):
            return False
        
        count1 = [0]*26
        count2 = [0]*26
        
        for i in range(len(s)):
            count1[ord(s[i]) - ord("a")] += 1
            count2[ord(t[i]) - ord("a")] += 1   
        return count1 == count2
        
#         chrsS = {}
#         chrsT = {}
        
#         for i in range(len(s)):
            
#             chrsS[s[i]] = 1 + chrsS.get(s[i], 0)
#             chrsT[t[i]] = 1 + chrsT.get(t[i], 0)
            
#         return chrsS == chrsT