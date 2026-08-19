class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> anagram_groups; // need to use ordered map as it doesn't require hashing a vector key, which is not possible
        for (string s : strs) {
            vector<int> counts(26, 0);
            for (char c : s) {
                ++counts[c - 'a'];
            }
            auto it = anagram_groups.find(counts);
            if (it != anagram_groups.end()) {
                it->second.push_back(s);
            } else {
                anagram_groups.insert({counts, {s}});
            }
        }
        vector<vector<string>> output;
        for (auto [key, val] : anagram_groups) {
            output.push_back(val);
        }
        return output;
    }
};
