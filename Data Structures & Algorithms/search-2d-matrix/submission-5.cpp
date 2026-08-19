class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // General idea: a two part binary search, to find the corresponding row
        // then the corresponding element in row once found

        // Find row
        int l = 0;
        int r = matrix.size() - 1;
        int end = matrix[0].size() - 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            // Shift left ptr
            if (target > matrix[mid][end]) {
                l = mid;
            } else if (target < matrix[mid][end]) {
                r = mid;
            } else return true; // the rare case we accidentally stumble upon the element
        }
        int row;
        if (matrix[l][end] >= target) {
            row = l;
        } else row = r;
        std::cout<<row;

        // Find element in row;
        if (matrix[row][0] > target) return false; // check first that range is valid
        int rl = 0;
        int rr = end;
        while (rr - rl > 1) {
            int mid = (rl + rr) / 2;
            if (target > matrix[row][mid]) {
                rl = mid;
            } else if (target < matrix[row][mid]) {
                rr = mid;
            } else return true;
        }
        return matrix[row][rl] == target || matrix[row][rr] == target;
    }
};
