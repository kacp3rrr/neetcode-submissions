class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        self.visit = set()
        self.NUM_ROWS = len(grid)
        self.NUM_COLS = len(grid[0])
        num_islands = 0

        def dfs(row, col) -> None:
            if (
                row < 0 or
                row >= self.NUM_ROWS or
                col < 0 or
                col >= self.NUM_COLS or
                (row, col) in self.visit or
                grid[row][col] == "0"    
            ):
                return
            else:
                self.visit.add((row, col))
                dfs(row + 1, col)
                dfs(row, col + 1)
                dfs(row - 1, col)
                dfs(row, col - 1)

        for row in range(self.NUM_ROWS):
            for col in range(self.NUM_COLS):
                if (grid[row][col] == "1" and (row,col) not in self.visit):
                    dfs(row, col)
                    num_islands += 1
        return num_islands
