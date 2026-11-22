
class Solution {
public:

    bool solve(vector<vector<char>>& board, string& word,
               int i, int j, int index) {

        // Word completely found
        if(index == word.size()) {
            return true;
        }

        // Boundary and character check
        if(i < 0 || j < 0 ||
           i >= board.size() || j >= board[0].size() ||
           board[i][j] != word[index]) {
            return false;
        }

        // Store current character
        char ch = board[i][j];

        // Mark visited
        board[i][j] = '#';

        // Explore all four directions
        bool found =
            solve(board, word, i + 1, j, index + 1) ||
            solve(board, word, i - 1, j, index + 1) ||
            solve(board, word, i, j + 1, index + 1) ||
            solve(board, word, i, j - 1, index + 1);

        // Backtrack: restore original character
        board[i][j] = ch;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(board[i][j] == word[0]) {
                    if(solve(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
