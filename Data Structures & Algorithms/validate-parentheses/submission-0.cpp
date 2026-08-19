class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses;
        if (s.length() % 2) return false;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                parentheses.push(c);
            } else {
                if (parentheses.empty()) return false;
                if ((c == ')' && parentheses.top() == '(') || (c == '}' && parentheses.top() == '{') || (c == ']' && parentheses.top() == '[')) {
                    parentheses.pop();
                } else {
                    return false;
                }
            } 
        }
        return parentheses.empty();
    }
};