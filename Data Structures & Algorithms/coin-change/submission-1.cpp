class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int c : coins) {
            if (c > amount) continue;
            dp[c] = 1;
            for (int j = c + 1; j <= amount; ++j) {
                if (dp[j - c] > 0) {
                    if (dp[j] > 0) dp[j] = min(dp[j], dp[j - c] + 1);
                    else dp[j] = dp[j - c] + 1;
                }
            }
        }
        return dp[amount];
    }
};