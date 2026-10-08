class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        res = 0
        path = set()
        seen = set()
        graph = [[] for _ in range(numCourses)]
        for a, b in prerequisites:
            graph[b].append(a)

        def dfs(node) -> bool:
            if node in path: 
                return True
            if node in seen:
                return False
            path.add(node)
            for child in graph[node]:
                if dfs(child):
                    return True
            path.remove(node)
            seen.add(node) # all paths for this given node explored, whatever is beyond is valid
            return False
        
        for course in range(numCourses):
            if dfs(course):
                return False
        return True
