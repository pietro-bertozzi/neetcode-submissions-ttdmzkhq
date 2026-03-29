class Solution {
public:
    int rob(vector<int>& nums) {
        int one = 0, two = 0, temp;
        for (int n : nums) {
            temp = two;
            two = max(one + n, two);
            one = temp;
        }
        return two;
    }
};
