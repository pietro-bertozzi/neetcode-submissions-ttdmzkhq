class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low = 100, best = 0;
        for (int p : prices) {
            if (p < low) {
                low = p;
            } else if (p - low > best) {
                best = p - low;
            }
        }
        return best;
    }
};
