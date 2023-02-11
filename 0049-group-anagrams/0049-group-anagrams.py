class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
        temp = {}
        dictsForS = []
        ansDict = {}
        for i in range(len(strs)):
            
            for j in range(len(strs[i])):
                
                temp[strs[i][j]] = 1 + temp.get(strs[i][j], 0)
                
            if temp not in dictsForS:
                dictsForS.append(temp)
                ansDict[len(dictsForS)-1] = [strs[i]]
            else:
                idx = dictsForS.index(temp)
                ansDict[idx].append(strs[i])

            temp = {}
        
        return list(ansDict.values())