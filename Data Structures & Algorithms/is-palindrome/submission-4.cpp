class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0; int right = s.length() - 1;
        
        while (left < right) {
            while (!isalnum(s[left])) left++;
            while (!isalnum(s[right])) right--;
            cout << s[left] << " " << s[right] << endl;
            if (left <= right && tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            ++left;
            --right;
        }

        return true;
    }
};
