class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sol = 0;
        for (int n : nums) {
            sol = n ^ sol;
        }
        return sol;
    }
};
