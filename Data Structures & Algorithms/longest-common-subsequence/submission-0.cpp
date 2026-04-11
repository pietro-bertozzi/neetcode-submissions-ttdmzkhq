class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        if (n < m) return longestCommonSubsequence(text2, text1);
        vector<vector<int>> dp(2, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i % 2][j] = text1[i - 1] == text2[j - 1] 
                    ? dp[(i - 1) % 2][j - 1] + 1
                    : max(dp[(i - 1) % 2][j], dp[i % 2][j - 1]);
            }
        }
        return dp[n % 2][m];
    }
};