class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // map of (row,col, or square) index to a set containing the numbers in that r/c/s
        unordered_map<int, unordered_set<char>> rows;
        unordered_map<int, unordered_set<char>> cols;
        unordered_map<int, unordered_set<char>> squares;
        // iterate through each element, put it in its respective row, col, and square, and check if the size
        // of each set increased. if it did not, it means there is a duplicate
        // problem guarantees a 9x9 board, and each entry is a valid digit, so we do not need to validate
        for (int i = 0; i < board.size(); ++i) { 
            for (int j = 0; j < board[i].size(); ++j) {
                char curr = board[i][j];
                // skip over an empty square
                if (curr == '.') continue;
                // compute index of current square as a function of current row and column
                // compute which row it starts at ((i/3) * 3) and then add the column offset (j/3)
                int squareIndex = (i/3) * 3 + (j/3);
                // store original sizes to check if insertion was successful. if size remains same after insertion
                // then the set has a duplicate, and we can return as an invalid sudoku board
                int rowSize = rows[i].size();
                int colSize = cols[j].size();
                int squareSize = squares[squareIndex].size();
                // (attempt to) insert the current digit into each container, and return false if any one
                // of these operations didn't succeed
                rows[i].insert(curr);
                cols[j].insert(curr);
                squares[squareIndex].insert(curr);
                int newRowSize = rows[i].size();
                int newColSize = cols[j].size();
                int newSquareSize = squares[squareIndex].size();
                if (newRowSize == rowSize || newColSize == colSize || newSquareSize == squareSize) {
                    return false;
                }
            }
        }
        // was not returned as false during the insertions, meaning our board is valid
        return true;
    }
};
