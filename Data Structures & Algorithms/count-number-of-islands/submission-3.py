class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        ROWS, COLS = len(grid), len(grid[0])
        ct = 0

        def dfs(row, col):
            if (
                not 0 <= row < ROWS or
                not 0 <= col < COLS or
                grid[row][col] == "0"
            ):
                return
            grid[row][col] = "0"
            dfs(row+1,col)
            dfs(row, col+1)
            dfs(row-1,col)
            dfs(row,col-1)
        
        for i in range(ROWS):
            for j in range(COLS):
                if grid[i][j] == "1":
                    ct += 1
                    dfs(i, j)
        return ct