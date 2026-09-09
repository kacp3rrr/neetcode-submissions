class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // -4, -1, -1, 0, 1, 2
        vector<vector<int>> triples;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[0] > 0) break;
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                if (left == i) ++left;
                if (right == i) --right;
                if (left >= right) break;
                int sum = nums[left] + nums[right] + nums[i];
                if (sum == 0) {
                    triples.push_back({nums[i], nums[left], nums[right]});
                    int currLeft = left;
                    int currRight = right;
                    while (left < right && nums[currLeft] == nums[left]) {
                        ++left;
                    }
                    while (left < right && nums[currRight] == nums[right]) {
                        --right;
                    }
                } else if (sum > 0) {
                    --right;
                } else {
                    ++left;
                }
            }
        }
        return triples;
    }
};
