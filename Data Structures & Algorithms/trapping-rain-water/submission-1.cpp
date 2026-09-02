class Solution {
public:
    int trap(vector<int>& height) {
        int total_rainwater = 0;
        int left = 0; int right = height.size() - 1;
        // computer prefix maximums, where max_left[i] is the biggest pillar left of height[i], and
        // same concept for the right
        vector<int> max_left(height.size());
        vector<int> max_right(height.size());
        while (right >= 0 && left < height.size()) {
            if (left == 0 && right == height.size() - 1) {
                max_left[0] = 0;
                max_right[right] = 0;
            } else {
                max_left[left] = max(height[left - 1], max_left[left - 1]);
                max_right[right] = max(height[right + 1], max_right[right + 1]);
            }
            ++left;
            --right;
        }
        for (int i = 0; i < height.size(); ++i) {
            total_rainwater += max(min(max_left[i], max_right[i]) - height[i], 0);
        }
        return total_rainwater;
    }
};
