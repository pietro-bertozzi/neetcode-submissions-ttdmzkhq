class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        unordered_set<int> seen;
        seen.reserve(nums.size());
        for (int n : nums) {
            if (!seen.insert(n).second) {
                return true;
            }
        }
        return false;
    }
};