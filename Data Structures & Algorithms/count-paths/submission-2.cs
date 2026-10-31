public class Solution {
    public int UniquePaths(int m, int n) {
        int[,] dp = new int[m, n]; 
        dp[0,0] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int curr = dp[i,j];
                if (i != m - 1) {
                    dp[i+1,j] += curr;
                }
                if (j != n - 1) {
                    dp[i,j+1] += curr;
                }
            }
        }

        return dp[m-1,n-1];
    }
}
