class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        # run bellman-ford for k + 1 iterations, which will find the cheapest path
        # to src within k stops. if not possible, then the min cost to src will remain
        # the initialized cost, for which we return -1
        prices = [float('inf')] * n 
        prices[src] = 0

        for _ in range(k+1):
            currPrices = list(prices)
            for u, v, cost in flights:
                if currPrices[u] != float('inf') and currPrices[u] + cost <= prices[v]:
                    prices[v] = currPrices[u] + cost

        cost = prices[dst]
        return cost if cost != float('inf') else -1
        