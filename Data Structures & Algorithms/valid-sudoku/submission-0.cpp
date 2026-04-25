class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        set<char> seen;
        for (int i = 0; i < n; ++i) {
            seen.clear();
            for (int j = 0; j < m; ++j) {
                if (seen.contains(board[i][j])) return false;
                if (board[i][j] != '.') seen.insert(board[i][j]);
            }
        }
        for (int j = 0; j < m; ++j) {
            seen.clear();
            for (int i = 0; i < n; ++i) {
                if (seen.contains(board[i][j])) return false;
                if (board[i][j] != '.') seen.insert(board[i][j]);
            }
        }
        for (int k = 0; k < 9; ++k) {
            seen.clear();
            for (int i = (k % 3) * 3; i < ((k % 3) + 1) * 3; ++i) {
                for (int j = (k / 3) * 3; j < ((k / 3) + 1) * 3; ++j) {
                    if (seen.contains(board[i][j])) return false;
                    if (board[i][j] != '.') seen.insert(board[i][j]);
                }
            }
        }
        return true;
    }
};
