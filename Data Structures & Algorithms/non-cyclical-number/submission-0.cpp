class Solution {
private:
    int sumOfSquaredDigs(int n) {
        int sum = 0;
        while (n > 0) {
            sum += pow(n % 10, 2);
            n /= 10; 
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> nums;
        int count = 0;
        while (count == nums.size()) {
            n = sumOfSquaredDigs(n);
            if (n == 1) return true;
            nums.insert(n); // won't add if duplicate exists, will disjoint set size with count/expected size, indicating loop
            ++count;
        }
        return false;
    }
};
