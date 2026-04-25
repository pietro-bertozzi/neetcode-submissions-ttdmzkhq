class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, set<char>> rows, columns;
        unordered_map<int, set<char>> squares;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                if (rows[i].contains(board[i][j]) ||
                    columns[j].contains(board[i][j]) ||
                    squares[i / 3 * 3 + j / 3].contains(board[i][j])) return false;
                rows[i].insert(board[i][j]);
                columns[j].insert(board[i][j]);
                squares[i / 3 * 3 + j / 3].insert(board[i][j]);
            }
        }
        return true;
    }
};
