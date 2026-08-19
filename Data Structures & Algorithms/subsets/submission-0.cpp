class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int index_tracker = pow(2,nums.size()) - 1;
        vector<vector<int>> pset;
        while (index_tracker >= 0) {
            vector<int> sset;
            for (int i = 0; i < nums.size(); ++i) {
                bool add_element = (index_tracker & (int)pow(2,i)) != 0;
                if (!add_element) {
                    sset.push_back(nums[i]);
                }
            }
            pset.push_back(sset);
            --index_tracker;
        }
        return pset;
    }
};