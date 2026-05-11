class Solution {
public:
    double myPow(double x, int n) {
        if (!n) return 1;
        double result = n > 0 ? x : 1 / x;
        if (n > 0) for (int i = 1; i < n; ++i) result *= x;
        else for (int i = 1; i < -n; ++i) result /= x;
        return result;
    }
};
