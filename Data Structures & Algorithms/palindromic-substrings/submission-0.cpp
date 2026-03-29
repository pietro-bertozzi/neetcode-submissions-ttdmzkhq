class Solution {
public:
    int countSubstrings(string s) {
        string t = "#";
        for (char c : s) {
            t += string(1, c) + "#";
        }
        int n = t.size();
        vector<int> dp(n, 0);
        int l = 0, r = 0, result = 0;
        for (int i = 0; i < n; ++i) {
            dp[i] = (i < r) ? min(r - i, dp[l + (r - i)]) : 0;
            while (i + dp[i] + 1 < n && i - dp[i] - 1 >= 0 &&
                   t[i + dp[i] + 1] == t[i - dp[i] - 1]) {
                dp[i]++;
            }
            if (i + dp[i] > r) {
                r = i + dp[i];
                l = i - dp[i];
            }
        }
        for (int i : dp) result += (i + 1) / 2;
        return result;
    }
};