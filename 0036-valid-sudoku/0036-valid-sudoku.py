class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in range(9):
            rowSet = set()
            colSet = set()
            for j in range(9):
                if board[i][j] == ".":
                    continue
                if board[i][j] in rowSet:
                    return False
                rowSet.add(board[i][j])
                
            for j in range(9):
                if board[j][i] == ".":
                    continue
                if board[j][i] in colSet:
                    return False
                colSet.add(board[j][i])
                
        for i in range(3):
            for j in range(3):
                boxSet = set()
                for x in range(3):
                    for y in range(3):
                        if board[3*i+y][3*j+x] == ".":
                            continue
                        if board[3*i+y][3*j+x] in boxSet:
                            return False
                        boxSet.add(board[3*i+y][3*j+x])
                        
        return True