class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        self.NUM_ROWS = len(grid)
        self.NUM_COLS = len(grid[0])
        max_area = 0

        def dfs(row, col) -> int:
            if (
                row < 0 or
                row >= self.NUM_ROWS or
                col < 0 or 
                col >= self.NUM_COLS or
                grid[row][col] == 0
            ):
                return 0
            else:
                grid[row][col] = 0
                return (
                    1 + dfs(row + 1, col)
                    + dfs(row - 1, col)
                    + dfs(row, col + 1)
                    + dfs(row, col - 1)
                )

        for row in range(self.NUM_ROWS):
            for col in range(self.NUM_COLS):
                if (grid[row][col] == 1):
                    max_area = max(max_area, dfs(row, col))
        return max_area
