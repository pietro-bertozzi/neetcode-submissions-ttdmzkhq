class Solution {
public:
    vector<int> nums;
    vector<vector<int>> result;

    void dfs(int i, vector<int> cur, int target) {
        if (!target) result.push_back(cur);
        if (target <= 0) return;
        for (int j = i; j < nums.size(); ++j) {
            cur.push_back(nums[j]);
            dfs(j, cur, target - nums[j]);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        this->nums = nums;
        //sort(nums.begin(), nums.end());
        dfs(0, {}, target);
        return result;
    }
};