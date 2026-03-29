class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        unordered_map<int, int> prev;
        prev.reserve(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            auto it = prev.find(complement);
            if (it != prev.end()) {
                return {it->second, i};
            }
            prev[nums[i]] = i;
        }
        return {};
    }
};