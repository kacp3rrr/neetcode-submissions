class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> differences;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = differences.find(target-nums[i]);
            if (it != differences.end()) {
                return {it->second, i};
            } 
            differences.insert({nums[i], i});
        }
    }
};
