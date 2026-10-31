class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[0] * n for _ in range(m)]
        dp[0][0] = 1
        for i in range(m):
            for j in range(n):
                if i == m-1 and j == n-1:
                    break

                curr = dp[i][j]
                if i != m-1:
                    dp[i+1][j] += curr
                if j != n-1:
                    dp[i][j+1] += curr
    
        print(dp)
        return dp[m-1][n-1]
        