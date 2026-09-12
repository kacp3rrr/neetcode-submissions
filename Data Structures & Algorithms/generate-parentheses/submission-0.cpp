class Solution {
private:
    vector<string> permutations;
    int n;
    void generate(string curr, int open, int close) {
        if (open == n && close == n) {
            permutations.push_back(curr);
        }
        if (open < n) {
            generate(curr + "(", open + 1, close);
        }
        if (close < open) {
            generate(curr + ")", open, close + 1);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        this->n = n;
        generate("", 0, 0);
        return permutations;
    }
};
