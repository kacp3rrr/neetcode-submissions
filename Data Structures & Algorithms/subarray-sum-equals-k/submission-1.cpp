class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // form prefix sum, track occurences
        unordered_map<int, int> freq;
        int prefixSum = 0;
        int res = 0;
        // store frequency of 0 as 1, for the case we have where a 
        // given element itself is k, so it would count as a subarray when
        // we check (prefixSum - k) against the map
        freq[0] = 1; 
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