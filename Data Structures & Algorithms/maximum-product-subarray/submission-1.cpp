class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), result = nums[0];
        int prefix = 0, suffix = 0;
        for (int i = 0; i < n; i++) {
            prefix = nums[i] * (prefix ? prefix : 1);
            suffix = nums[n - 1 - i] * (suffix ? suffix : 1);
            result = max(result, max(prefix, suffix));
        }
        return result;
    }
};