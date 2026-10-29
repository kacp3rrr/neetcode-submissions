class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        memo = [-1] * len(cost)

        def findCost(stair):
            # we've gone past a valid path, so invalidate by making float('inf')
            if stair >= len(cost):
                return 0

            if memo[stair] != -1:
                return memo[stair]
            else:
                memo[stair] = cost[stair] + min(findCost(stair + 1), findCost(stair + 2))
            return memo[stair]
        
        return min(findCost(0), findCost(1))