class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges) + 1
        graph = [[] for _ in range(n)]
        for a,b in edges:
            graph[a].append(b)
            graph[b].append(a)

        # run dfs to detect the cycle in the graph caused by the 
        # redundant edge. we maintain a list called visit. when dfs
        # enters an already visited node, mark it as the cycle start,
        # and for successive recursive calls, add to the cycle until we close
        # it by revisiting the same node
        cycle = set()
        visit = [False] * n
        startOfCycle = -1

        def dfs(node, parent) -> bool:
            nonlocal startOfCycle
            if visit[node]:
                startOfCycle = node
                return True
            
            visit[node] = True
            for neighbor in graph[node]:
                if neighbor == parent:
                    continue

                # if we revisit 
                if dfs(neighbor, node):
                    if startOfCycle != -1:
                        cycle.add(node)
                    if startOfCycle == node:
                        startOfCycle = -1
                    return True
            return False

        # run dfs to populate the cycle. then, we want to 
        # go through the edges until we find one that contains two nodes
        # in a cycle. removing this edge would remove the cycle, so that is
        # our redundant edge. problem specifies to return the edge that appears
        # last if multiple answers exist, so we just scan backwards for the first
        # instance
        dfs(1, -1)

        for a,b in reversed(edges):
            if a in cycle and b in cycle:
                return [a,b]
        

