class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size() + 1;
        int result = (n * (n - 1)) / 2;
        for (int n : nums) result -= n; 
        return result;
    }
};
