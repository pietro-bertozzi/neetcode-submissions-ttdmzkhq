class Solution {
public:
    int characterReplacement(std::string s, int k) {
        unordered_map<char, int> count;
        int result = 0, l = 0, maxf = 0;
        for (int r = 0; r < s.size(); r++) {
            count[s[r]]++;
            maxf = max(maxf, count[s[r]]);
            if (r - l + 1 - maxf > k) {
                count[s[l++]]--;
            }
            result = max(result, r - l + 1);
        }
        return result;
    }
};