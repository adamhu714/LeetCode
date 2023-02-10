class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        ones=deque()
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == 1:
                    ones.append((i, j))
        n = len(grid)
        if len(ones) in [0, n**2]:
            return -1
        distance = -1
        visited = set(ones)
        while ones:
            
            for i in range(len(ones)):                
                r,c = ones.popleft()
                
                if (r+1, c) not in visited and r + 1 < n:
                    if not grid[r+1][c]:
                        ones.append((r+1,c))
                        visited.add((r+1,c))

                if (r-1, c) not in visited and r - 1 > -1:
                    if not grid[r-1][c]:
                        ones.append((r-1,c))
                        visited.add((r-1,c))

                if (r, c+1) not in visited and c + 1 < n:
                    if not grid[r][c+1]:
                        ones.append((r,c+1))
                        visited.add((r,c+1))
                    
                if (r, c-1) not in visited and c - 1 > -1:
                    if not grid[r][c-1]:
                        ones.append((r,c-1))
                        visited.add((r,c-1))

            distance += 1
        
        return distance