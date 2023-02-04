class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        
        if len(s1) > len(s2):
            return False
        
        window1 = [0]*26
        window2 = [0]*26
        
        for i in range(len(s1)):
            window1[ ord(s1[i])-ord('a') ] += 1
            window2[ ord(s2[i])-ord('a') ] += 1
       
        if window1 == window2:
            return True
        
        for i in range(len(s2)-len(s1)):
            window2[ ord(s2[i])-ord('a') ] -= 1
            window2[ ord(s2[i+len(s1)])-ord('a') ] += 1
            if window1 == window2:
                return True
        return False