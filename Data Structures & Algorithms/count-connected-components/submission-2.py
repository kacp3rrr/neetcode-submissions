class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        seen = set()
        res = 0
        adj = [[] for _ in range(n)]
        for a, b in edges:
            adj[a].append(b)
            adj[b].append(a)
        
        def dfs(node):
            if (
                node in seen
            ): 
                return
            seen.add(node)
            for neighbor in adj[node]:
                dfs(neighbor)
        
        for node in range(n):
            if node not in seen:
                res += 1
                dfs(node)
        return res
            
