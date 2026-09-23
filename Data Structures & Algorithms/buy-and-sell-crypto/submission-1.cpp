class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPrice = 0;
        int minPrice = 101; // price cannot exceed 100
        for (int p : prices) {
            minPrice = min(minPrice, p);
            maxPrice = max(maxPrice, p - minPrice);
        }
        return maxPrice;
    }
};
