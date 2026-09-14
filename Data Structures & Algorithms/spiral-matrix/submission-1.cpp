class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // store the bounds of the rows and cols, which update on every pass
        // upper bounds 
        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0; 
        int right = matrix[0].size() - 1;
        vector<int> output;
        while (top <= bottom && left <= right) {
            for (int j = left; j <= right; ++j) {
                output.push_back(matrix[top][j]);
            }
            ++top;
            // early termination case for when we reach the center
            if (top > bottom) break;
            for (int i = top; i <= bottom; ++i) {
                output.push_back(matrix[i][right]);
            }
            --right;
            // second early termination case for when we reach the center
            if (left > right) break; 
            for (int j = right; j >= left; --j) {
                output.push_back(matrix[bottom][j]);
            }
            --bottom;
            for (int i = bottom; i >= top; --i) {
                output.push_back(matrix[i][left]);
            }
            ++left;
        }
        return output;
    }
};
