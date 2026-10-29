class Solution:
    def rob(self, nums: List[int]) -> int:
        dp = [0] * len(nums)
        for i in range(len(nums)):
            if i == 0:
                dp[0] = nums[0]
            elif i == 1:
                dp[1] = max(dp[0], nums[1])
            else:
                dp[i] = max(nums[i] + dp[i-2], dp[i-1])
        return max(dp)