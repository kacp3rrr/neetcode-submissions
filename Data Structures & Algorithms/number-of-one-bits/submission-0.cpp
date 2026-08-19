class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for (int i = 0; i < 32; ++i) {
            count += (((1U << i) & n) == 0) ? 0 : 1;
        }
        return count;
    }
};
