class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, int> rows, columns;
        unordered_map<int, int> squares;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                if (rows[i] & 1 << board[i][j] ||
                    columns[j] & 1 << board[i][j] ||
                    squares[i / 3 * 3 + j / 3] & 1 << board[i][j]) return false;
                rows[i] |=  1 << board[i][j];
                columns[j] |= 1 << board[i][j];
                squares[i / 3 * 3 + j / 3] |= 1 << board[i][j];
            }
        }
        return true;
    }
};
