class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        # pad the array with 1s for boundary cases for a base multiplication case
        nums = [1] + nums + [1]
        n = len(nums)
        # dp array where dp[i][j] is the maximum number of coins we get for popping in a given
        # window (i,j), both bounds exclusive
        dp = [[0 for _ in range(n)] for _ in range(n)]

        # iterate based on window length
        for length in range(2, n):
            for i in range(n-length):
                j = i + length
                currMax = 0
                for k in range(i+1, j):
                    # for any given range (i,j), we iterate through every
                    # possible choice of balloon k being the last one we pop,
                    # and we check on the smaller windows on the left and right
                    # of k recursively
                    currMax = max(currMax, 
                        dp[i][k] + dp[k][j] + nums[i] * nums[k] * nums[j])
                dp[i][j] = currMax

        # dp[0][n-1] represents the full range of nums
        return dp[0][n-1]