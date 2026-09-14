class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // the layer that defines the boundary/perimiter we are currently rotating
        // the top and left bounds are rows/col currLayer
        // the bottom and right bouhnds are rows/col n - currLayer - 1. this will progressively
        // move the window inward, as we are rotating the layers of the matrix from out to in
        int currLayer = 0;
        int n = matrix.size();
        while (currLayer < (n - currLayer - 1)) {
            // iterate over the top row of the layer, using i as a dynamic reference and
            // currLayer as a base reference for determining pointers
            for (int i = currLayer; i < n - currLayer - 1; ++i) {
                // perform the rotation at each step, getting the value at each pointer going
                // either right, up, down, or left
                int right = matrix[currLayer][i];
                int down = matrix[i][n-currLayer-1];
                int left = matrix[n-currLayer-1][n-i-1];
                int up = matrix[n-i-1][currLayer];
                // right pointer gets up val, down pointer gets right val, left pointer gets
                // down val, up pointer gets left val
                matrix[currLayer][i] = up;
                matrix[i][n-currLayer-1] = right;
                matrix[n-currLayer-1][n-i-1] = down;
                matrix[n-i-1][currLayer] = left;
            }
            ++currLayer;
        }
    }
};
