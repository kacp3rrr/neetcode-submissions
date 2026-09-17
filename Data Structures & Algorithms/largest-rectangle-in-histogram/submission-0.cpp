class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // maintain monotonic stack of bar heights
        int maxArea = 0;
        int curr; int top;
        stack<int> barHeights;
        for (int i = 0; i < heights.size(); ++i) {
            while (!barHeights.empty() && heights[i] < heights[barHeights.top()]) {
                top = barHeights.top();
                barHeights.pop();
                int width;
                if (barHeights.empty()) {
                    width = i;
                } else {
                    width = i - barHeights.top() - 1;
                }
                maxArea = max(maxArea, heights[top] * width);
            }
            barHeights.push(i);
        }
        // for remaining items in stack, prev smaller is just the item below
        while (!barHeights.empty()) {
            top = barHeights.top();
            barHeights.pop();
            curr = heights[top] * (barHeights.empty() ? heights.size() : heights.size() - barHeights.top() - 1);
            maxArea = max(maxArea, curr);
        }
        return maxArea;
    }
};
