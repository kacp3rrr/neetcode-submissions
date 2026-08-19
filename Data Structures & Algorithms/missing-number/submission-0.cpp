class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // return to explore the XOR solution
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }
        int n = nums.size();
        int totalSum = n * (n + 1) / 2;
        return totalSum - sum;
    }
};
