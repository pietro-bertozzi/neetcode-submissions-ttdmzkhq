class Solution {
public:
    int getSum(int a, int b) {
        int c;
        while (b) {
            c = (a & b) << 1;
            a ^= b;
            b = c;
        }
        return a;
    }
};