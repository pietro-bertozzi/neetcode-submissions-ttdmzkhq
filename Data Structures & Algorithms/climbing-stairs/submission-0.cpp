class Solution {
public:
    int climbStairs(int n) {
        int one = 1, two = 1;
        for (int i = 0; i < n; ++i) {
            if (i % 2) two += one;
            else one += two; 
        }
        return n % 2 ? two : one;
    }
};
