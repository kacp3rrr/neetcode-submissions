class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        NUMR, NUMC = len(matrix), len(matrix[0])
        # dp matrix, where dp[i][j] represents the longest path that
        # originates at matrix[i][j]
        dp = [[1 for _ in range(NUMC)] for _ in range(NUMR)]
        dirs = [(1,0), (-1,0), (0,1), (0,-1)]
        res = 0

        def dfs(row, col, prev) -> int:
            if (
                not (0 <= row < NUMR) or
                not (0 <= col < NUMC) or
                matrix[row][col] <= prev
            ):
                return 0
            if dp[row][col] != 1:
                return dp[row][col]
            maxLength = 0
            for dr, dc in dirs:
                nr, nc = row+dr, col+dc
                maxLength = max(maxLength, dfs(nr, nc, matrix[row][col]))
            dp[row][col] = 1 + maxLength
            return 1 + maxLength
        
        for i in range(NUMR):
            for j in range(NUMC):
                res = max(
                    res, dfs(i, j, -1)) # start with prev=-1 for first call
        
        return res