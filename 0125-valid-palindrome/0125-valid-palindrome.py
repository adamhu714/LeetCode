class Solution:
    def isPalindrome(self, s: str) -> bool:
        l = 0
        r = len(s) - 1
        while l < r:
            while l < r and self.isAlphaNumeric(s[l]) == False:
                l = l + 1
            while l < r and self.isAlphaNumeric(s[r]) == False:
                r = r - 1
            if s[l].lower() != s[r].lower():
                return False
            l = l + 1
            r = r - 1
        return True
    
    def isAlphaNumeric(self, char):
        return ((ord("a") <= ord(char) and ord(char) <= ord("z")) or 
               (ord("A") <= ord(char) and ord(char) <= ord("Z")) or 
               (ord("0") <= ord(char) and ord(char) <= ord("9")))