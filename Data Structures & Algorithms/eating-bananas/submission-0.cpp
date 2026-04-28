class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = piles[0];
        for (int i = 1; i < piles.size(); ++i) r = max(piles[i], r);
        int kbest = 1;
        while (l <= r) {
            int k = (l + r) / 2, t = 0;
            for (int p : piles) t += (p + k - 1) / k;
            if (t <= h) {
                kbest = k;
                r = k - 1;
            } else l = k + 1;
        }
        return kbest;
    }
};
