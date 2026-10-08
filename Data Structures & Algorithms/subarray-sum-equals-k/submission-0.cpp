class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // form prefix sum, track occurences
        unordered_map<int, int> freq;
        freq[0] = 1; // to have in case a single element itself is a subarray
        int prefixSum = 0;
        int res = 0;
        // for each prefix sum, find how many previously found pref sums
        // equal pref - k. each one forms a subarray ending at the current index
        // that sums to k. then record the current prefix's occurence
        for (size_t i = 0; i < nums.size(); ++i) {
            prefixSum += nums[i];
            res += freq[prefixSum - k];
            ++freq[prefixSum];
        }
        return res;
    }
};