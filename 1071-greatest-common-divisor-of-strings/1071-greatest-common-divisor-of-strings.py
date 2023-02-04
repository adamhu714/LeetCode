class Solution:
    
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if len(str1) > len(str2):
            large = str1
            small = str2
        else:
            large = str2
            small = str1
        return self.checkForSub(small, large, small)
        
    
    def checkForSub(self, small, large, section):
        if section == "":
            return ""
        
        if len(large) % len(section) != 0 or len(small) % len(section) != 0:
            return self.checkForSub(small, large, section[0:-1])
        
        check = {large[i*len(section):(i+1)*len(section)] for i in range(int(len(large)/len(section)))}
        check2 = {small[i*len(section):(i+1)*len(section)] for i in range(int(len(small)/len(section)))}
        check.add(section)
        check2.add(section)
        if len(check) == 1 and len(check2) == 1:
            return section
        else:
            return self.checkForSub(small, large, section[0: -1])