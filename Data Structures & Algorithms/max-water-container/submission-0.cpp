class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_area = -1;
        int left = 0;
        int right = heights.size() - 1;
        while (left < right) {
            int curr_area = min(heights[left], heights[right]) * (right - left);
            if (curr_area > max_area) max_area = curr_area;
            if (heights[left] < heights[right]) {
                ++left;
            } else --right;
        }
        return max_area;
    }
};
