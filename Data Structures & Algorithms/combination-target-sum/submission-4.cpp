class Solution {
public:
    vector<int> nums;
    vector<vector<int>> result;

    void dfs(int i, vector<int> cur, int target) {
        if (!target) {
            result.push_back(cur);
            return;
        }
        for (int j = i; j < nums.size(); ++j) {
            if (target - nums[j] < 0) break;
            cur.push_back(nums[j]);
            dfs(j, cur, target - nums[j]);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        this->nums = nums;
        vector<int> cur;
        dfs(0, cur, target);
        return result;
    }
};