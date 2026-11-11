class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        n = len(gas)
        overallTank = 0
        currentTank = 0
        index = 0

        for i in range(n):
            currDiff = gas[i] - cost[i]
            currentTank += currDiff
            overallTank += currDiff
            if currentTank < 0:
                index = i + 1
                currentTank = 0
        
        return -1 if overallTank < 0 else index
