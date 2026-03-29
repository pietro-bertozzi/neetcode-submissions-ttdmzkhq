class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        int best = 0;
        for (int n : nums) {
            if (!mp[n]) {
                mp[n] = mp[n - 1] + mp[n + 1] + 1;
                mp[n - mp[n - 1]] = mp[n + mp[n + 1]] = mp[n];
                best = max(best, mp[n]);
            }
        }
        return best;
    }
};