class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        for (int i = 0; i < 32; ++i) {
            int x = 0, y = 0;
            int mask = 1 << i;
            for (int num : nums) if (num & mask) x++;
            for (int i = 1; i < n; i++) if (i & mask) y++;
            if (x > y) result |= mask;

        }
        return result;
    }
};