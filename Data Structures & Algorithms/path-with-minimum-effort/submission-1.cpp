class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int numRows = heights.size(), numCols = heights[0].size();
        vector<vector<int>> effort(numRows, vector<int>(numCols, INT_MAX));
        effort[0][0] = 0;

        // comparators on vectors work lexigraphically so we can use std::greater
        // minheap storing (currEffort, row, col), ordering it by least effort like
        // in standard dijkstra's
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        minHeap.push({0,0,0});

        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        while (!minHeap.empty()) {
            const vector<int> curr = minHeap.top();
            minHeap.pop();
            int currEffort = curr[0], row = curr[1], col = curr[2];

            if (row == numRows - 1 && col == numCols - 1) {
                return currEffort;
            }
            if (currEffort > effort[row][col]) {
                continue;
            }

            for (const auto& [dr, dc] : dirs) {
                int nr = row + dr, nc = col + dc;
                if (nr < 0 || nr >= numRows || nc < 0 || nc >= numCols) {
                    continue;
                }
                int currJump = abs(heights[row][col] - heights[nr][nc]);
                int newEffort = max(currEffort, currJump);
                if (newEffort < effort[nr][nc]) {
                    effort[nr][nc] = newEffort;
                    minHeap.push({newEffort, nr, nc});
                }
            }
        }
        return 0;
    }
};