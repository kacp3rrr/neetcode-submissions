class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        vector<int> dp(amount + 1, 0);
        sort(coins.begin(), coins.end());

        for (int i = 1; i < dp.size(); ++i) {
            long currMin = INT_MAX;
            for (int coin : coins) {
                if (coin > i) break;
                int currDiff = dp[i - coin];
                currMin = min(currMin, (long)currDiff + 1);
            }
            dp[i] = (int)currMin;
        }
        return dp[amount] != INT_MAX ? dp[amount] : -1;
    }
};
