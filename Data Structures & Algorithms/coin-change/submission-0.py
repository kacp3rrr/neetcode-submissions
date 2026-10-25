class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if amount == 0:
            return 0
        dp = [0] * (amount + 1)
        coins.sort()
        # bottom up approach, where in dp, index i represents the minimum number of coins to make that value
        for i in range(1, len(dp)):
            currMin = float('inf')
            for j in range(len(coins)):
                if coins[j] > i:
                    break
                numCoinsForDiff = dp[i - coins[j]]
                currMin = min(numCoinsForDiff + 1, currMin)
            dp[i] = currMin
        return dp[amount] if dp[amount] < float('inf') else -1
                    