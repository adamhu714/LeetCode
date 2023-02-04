class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        separate = [""] * numRows
        for i in range(len(s)):
            separate[numRows - 1 - (abs(numRows - 1 - (i % (2*(numRows - 1)) )))] += s[i]
        return "".join(separate)