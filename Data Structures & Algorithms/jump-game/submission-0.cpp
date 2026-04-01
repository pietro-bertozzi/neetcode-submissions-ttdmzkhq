class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), distance = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (distance < i) return false;
            distance = max(i + nums[i], distance);
        }
        return distance >= n - 1;
    }
};
