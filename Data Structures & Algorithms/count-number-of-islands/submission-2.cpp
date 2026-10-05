class Solution {
private:
    void dfs(vector<vector<char>>& v, int row, int col) {
        if (
            row < 0 ||
            row >= v.size() ||
            col < 0 ||
            col >= v[0].size() ||
            v[row][col] == '0'
        ) {
            return;
        } else {
            v[row][col] = '0';
            dfs(v, row + 1, col);
            dfs(v, row - 1, col);
            dfs(v, row, col + 1);
            dfs(v, row, col - 1);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                if (grid[row][col] == '1') {
                    ++res;
                    dfs(grid, row, col);
                }
            }
        }
        return res;
    }
};
