class Solution {
public:
    string longestPalindrome(string s) {
        string t = "#";
        for (char c : s) {
            t += string(1, c) + "#";
        }
        int n = t.size();
        vector<int> dp(n, 0);
        int l = 0, r = 0, c = 0, len = 0;
        for (int i = 0; i < n; ++i) {
            dp[i] = (i < r) ? min(r - i, dp[l + r - i]) : 0;
            while (i + dp[i] + 1 < n && i - dp[i] - 1 >= 0 &&
                   t[i + dp[i] + 1] == t[i - dp[i] - 1]) {
                dp[i]++;
            }
            if (i + dp[i] > r) {
                r = i + dp[i];
                l = i - dp[i];
            }
            if (dp[i] > len) {
                len = dp[i];
                c = i;
            }
        }
        return s.substr((c - len) / 2, len);
    }
};