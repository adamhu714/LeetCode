class Solution:
    def findPaths(self, m: int, n: int, maxMove: int, startRow: int, startColumn: int) -> int:
        memo = [[[0 for k in range(maxMove+1)] for j in range(n)] for i in range(m)]
        vis = [[[False for k in range(maxMove+1)] for j in range(n)] for i in range(m)]
        N = maxMove
        i = startRow
        j = startColumn
        return self.findPathsDFS(m, n, N, i, j, memo, vis) % 1000000007
        
    
    def findPathsDFS(self, m, n, N, i, j, memo, vis):
        if i == m or j == n or i < 0 or j < 0:
            return 1
        if N == 0:
            return 0
        if vis[i][j][N] == True:
            return memo[i][j][N]
        memo[i][j][N] = (self.findPathsDFS(m, n, N - 1, i - 1, j, memo, vis) + 
                            self.findPathsDFS(m, n, N - 1, i + 1, j, memo, vis)
                            + self.findPathsDFS(m, n, N - 1, i, j - 1, memo, vis)
                            + self.findPathsDFS(m, n, N - 1, i, j + 1, memo, vis))
        vis[i][j][N] = True
        return memo[i][j][N]