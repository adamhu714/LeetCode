class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        setOfStrings = set()
        duplicates = set()
        
        for s in arr:
            if s in setOfStrings:
                duplicates.add(s)
                continue
            setOfStrings.add(s)
        
        count = k
        
        for s in arr:
            if s not in duplicates:
                if count == 1:
                    return s
                count = count - 1
        
        return ""