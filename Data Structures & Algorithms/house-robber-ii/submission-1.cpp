class Solution {
public:
    int rob1(vector<int>& nums, int start, int end) {
        int one = 0, two = 0, temp;
        for (int i = start; i < end; ++i) {
            temp = two;
            two = max(one + nums[i], two);
            one = temp;
        }
        return two;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        return max(rob1(nums, 0, n - 1), rob1(nums, 1, n));
    }
};