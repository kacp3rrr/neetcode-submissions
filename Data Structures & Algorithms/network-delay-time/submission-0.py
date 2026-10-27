class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        dist = [float('inf')] * (n+1)
        dist[0] = dist[k] = 0
        # heap of tuples of form (distance, node)
        minheap = [(0,k)]

        while minheap:
            currDist, currNode = heapq.heappop(minheap)
            if currDist > dist[currNode]:
                continue
            
            for u, v, time in times:
                if u != currNode:
                    continue

                if dist[u] + time < dist[v]:
                    dist[v] = dist[u] + time
                    heapq.heappush(minheap, (dist[v], v))
        
        return max(dist) if max(dist) != float('inf') else -1