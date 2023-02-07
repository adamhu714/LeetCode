class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        
        # Want to find longest stretch of trees where there are only two types of tree
        
        # Sliding window across and store largest length of sliding window 
        # before 3rd type of tree introduced
        
        
        maxLength = 1
        i = 0
        j = 1
        newI = 1
        
        a = fruits[0]
        
        while j < len(fruits):
            
            if fruits[j] != a and fruits[j] != fruits[i]:
                if a == fruits[i]:
                    a = fruits[j]
                    if j - i + 1 > maxLength:
                        maxLength = j - i + 1
                    newI = j
                else:
                    i = newI
                    a = fruits[i+1]
                    newI += 1
                    j -= 1
            else:
                if fruits[newI] != fruits[j]:
                    newI = j
                if j - i + 1 > maxLength:
                    maxLength = j - i + 1
            print(i," ",j)
            j += 1
            
        
        return maxLength