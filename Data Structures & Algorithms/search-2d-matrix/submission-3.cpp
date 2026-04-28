class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int last = matrix[0].size() - 1;
        int m, l = 0, r = matrix.size() - 1;
        while (l <= r) {
            m = (l + r) / 2;
            if (matrix[m][0] > target) r = m - 1;
            else if (matrix[m][last] < target) l = m + 1;
            else break;
        }
        l = 0, r = last;
        while (l <= r) {
            int n = (l + r) / 2;
            if (matrix[m][n] > target) r = n - 1;
            else if (matrix[m][n] < target) l = n + 1;
            else return true;
        }
        return false;
    }
};
