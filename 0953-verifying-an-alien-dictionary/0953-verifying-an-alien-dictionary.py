class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        
        values = {}
        for i in range(26):
            values[order[i]] = i
        
        for i in range(len(words)-1):
            for j in range(len(words[i])):
                if j > len(words[i+1])-1:
                    return False
                elif values[words[i][j]] > values[words[i+1][j]]:
                    return False
                elif values[words[i][j]] < values[words[i+1][j]]:
                    break
        return True