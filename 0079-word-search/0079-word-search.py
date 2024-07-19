class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        ROWS = len(board)
        COLS = len(board[0])
        path = set()
        def dfs(i,j,c):
            if len(word) == c:
                return True
            if i < 0 or j < 0 or i >= ROWS or j >= COLS or (i, j) in path or board[i][j] != word[c]:
                return False
            path.add((i,j))
            res = (dfs(i - 1, j, c+1) or
                dfs(i + 1, j, c+1) or
                dfs(i, j - 1, c+1) or
                dfs(i, j + 1, c+1))
            path.remove((i,j))
            return res
        for i in range(ROWS):
            for j in range(COLS):
                if dfs(i, j, 0):
                    return True
        return False