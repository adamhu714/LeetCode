class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        
        if len(p) > len(s):
            return []
        
        window1 = [0]*26
        window2 = [0]*26
        idxs = []
        
        for i in range(len(p)):
            window1[ ord(p[i])-ord('a') ] += 1
            window2[ ord(s[i])-ord('a') ] += 1
       
        if window1 == window2:
            idxs.append(0)
        
        for i in range(len(s)-len(p)):
            window2[ ord(s[i])-ord('a') ] -= 1
            window2[ ord(s[i+len(p)])-ord('a') ] += 1
            if window1 == window2:
                idxs.append(i+1)
        return idxs