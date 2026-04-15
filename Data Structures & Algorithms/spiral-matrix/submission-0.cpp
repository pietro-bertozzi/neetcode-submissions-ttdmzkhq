class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> result;
        vector<int> steps = {m, n - 1};
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int i = 0, j = -1, d = 0;
        while (steps[d % 2]) {
            for (int k = 0; k < steps[d % 2]; ++k) {
                i += directions[d].first;
                j += directions[d].second;
                result.push_back(matrix[i][j]);
            }
            steps[d % 2]--;
            d = (d + 1) % 4;
        }
        return result;
    }
};