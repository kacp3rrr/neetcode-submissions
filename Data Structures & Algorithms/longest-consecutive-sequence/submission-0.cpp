class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // make array into hash set for O(1) lookup, for finding starts of sequences
        unordered_set<int> numSet(nums.begin(), nums.end());
        // when we find a candidate for the beginning of a sequence, in that its 
        // immediate predecessor does not exist in the array, we iteratively attempt to build the
        // sequence by finding the successive elements until we can't, then keeping track of the largest
        // sequence we've found so far
        int largestSequenceSize = 0;
        for (int n : numSet) {
            if (numSet.find(n - 1) == numSet.end()) {
                int currentSequenceSize = 1;
                int currentNumber = n;
                while (numSet.find(currentNumber+1) != numSet.end()) {
                    ++currentSequenceSize;
                    ++currentNumber;
                }
                largestSequenceSize = max(currentSequenceSize, largestSequenceSize);
            }
        }
        return largestSequenceSize;
    }
};
