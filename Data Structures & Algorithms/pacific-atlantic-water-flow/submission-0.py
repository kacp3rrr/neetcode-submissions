class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        # make set of tiles that we know from which they will flow into one of the two oceans
        ROWS, COLS = len(heights), len(heights[0])
        atlantic, pacific = set(), set()
        dirs = [(1,0),(-1,0),(0,1),(0,-1)]

        # dfs helper
        def dfs(row, col, seen, prevHeight):
            if (
                (row, col) in seen or
                row < 0 or col < 0 or
                row >= ROWS or col >= COLS or
                heights[row][col] < prevHeight
            ):
                return
            seen.add((row, col))
            for dr, dc in dirs:
                dfs(row+dr, col+dc, seen, heights[row][col])
        
        # run dfs on tiles that border the pacific
        for row in range(ROWS):
            if row > 0:
                dfs(row, 0, pacific, 0)
            else:       
                for col in range(COLS):
                    dfs(row, col, pacific, 0)
        
        # run dfs on tiles that border the atlantic
        for row in range(ROWS):
            if row != ROWS - 1:
                dfs(row, COLS-1, atlantic, 0)
            else:       
                for col in range(COLS):
                    dfs(row, col, atlantic, 0)
        
        # populate result array with row, col pairs that appear in both sets
        res = []
        for row in range(ROWS):
            for col in range(COLS):
                if (row, col) in atlantic and (row, col) in pacific:
                    res.append([row, col])

        return res