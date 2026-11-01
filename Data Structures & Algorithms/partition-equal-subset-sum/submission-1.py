class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        total = sum(nums)
        if total % 2:
            return False

        half = total // 2
        n = len(nums)
        # 2d DP grid, where we have columns for each possible sum up to total/2
        # and rows representing using some subset of the first i numbers
        # we can simply make this 2 rows, and at the end of each pass make the 
        # second row the first (saving space)
        dp = [[False for _ in range(half + 1)] for _ in range(2)] 

        dp[0][0] = True
        for i in range(n):
            for c in range(half+1):
                dp[1][c] = dp[0][c] or (dp[0][c-nums[i]] if c-nums[i] >= 0 else False)
            
            dp[0], dp[1] = dp[1], [False for _ in range(half+1)]
        
        return dp[0][half]