class Solution {
public:
    void helper(int i, vector<int>& nums, int target, vector<int>& cur, vector<vector<int>>& result) {
        if(i >= nums.size() || target < 0) {
            return;
        }
        if(!target) {
            result.push_back(cur);
            return;
        }
        cur.push_back(nums[i]);
        helper(i, nums, target - nums[i], cur, result);
        cur.pop_back();
        helper(i + 1, nums, target, cur, result);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> cur;
        helper(0, nums, target, cur, result);
        return result;
    }
};
