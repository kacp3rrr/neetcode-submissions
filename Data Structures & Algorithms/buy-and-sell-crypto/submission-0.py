class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxPrice = 0
        minPrice = float("inf")
        for p in prices:
            minPrice = min(minPrice, p)
            maxPrice = max(maxPrice, p - minPrice)
        return maxPrice