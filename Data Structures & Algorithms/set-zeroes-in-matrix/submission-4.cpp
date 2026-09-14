class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // need some way to track the top row
        bool topRowZero = false;
        bool leftColZero = false;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (i == 0 && matrix[i][j] == 0) {
                    topRowZero = true;
                }
                if (j == 0 && matrix[i][j] == 0) {
                    leftColZero = true;
                }
                if (i != 0 && j != 0 && matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        // go through the top row, and for each zero entry, zero out the entire column
        for (int j = 1; j < matrix[0].size(); ++j) {
            if (matrix[0][j] == 0) {
                int i = 1;
                while (i < matrix.size()) {
                    matrix[i][j] = 0;
                    ++i;
                }
            }
        }
        // go through the left col, and for each zero entry, zero out the entire row
        for (int i = 1; i < matrix.size(); ++i) {
            if (matrix[i][0] == 0) {
                int j = 1;
                while (j < matrix[i].size()) {
                    matrix[i][j] = 0;
                    ++j;
                }
            }
        }
        // lastly, process topRowZero and leftColZero
        if (topRowZero) {
            int j = 0;
            while (j < matrix[0].size()) {
                matrix[0][j] = 0;
                ++j;
            }
        }
        if (leftColZero) {
            int i = 0;
            while (i < matrix.size()) {
                matrix[i][0] = 0;
                ++i;
            }
        }
    }
};
