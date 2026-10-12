class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        stack = []
        res = [0] * n
        for i in range(n):
            curr = temperatures[i]
            while(stack and temperatures[stack[-1]] < curr):
                currIndex = stack.pop()
                res[currIndex] = i - currIndex
            stack.append(i)
        return res