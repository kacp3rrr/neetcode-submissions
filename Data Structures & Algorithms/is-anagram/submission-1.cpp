class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        vector<int> counts(26, 0); // array of 26 0's
        for (int i = 0; i < s.length(); ++i) { // at the end, if valid anagram, all counts of letters in s will be balanced out by the subtractions done for t
            ++counts[s[i] - 'a'];
            --counts[t[i] - 'a'];
        } 
        for (int n : counts) {
            if (n != 0) {
                return false;
            }
        }
        return true; 
    }
};
