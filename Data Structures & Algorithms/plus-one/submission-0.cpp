class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int idx = digits.size() - 1;
        while (idx >= 0 && (digits[idx] + 1) == 10) {
            digits[idx] = 0;
            --idx;
        }
        if (idx < 0) {
            digits.push_back(0);
            digits[0] = 1;
        } else {
            digits[idx] += 1;
        }
        return digits;
    }
};