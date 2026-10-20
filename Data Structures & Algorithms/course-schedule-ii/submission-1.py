class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        # compute indegrees of all courses, then append all with indegree 0 into the 
        # queue
        indegrees = [0] * numCourses
        graph = defaultdict(list)
        for course, prereq in prerequisites:
            graph[prereq].append(course)
            indegrees[course] += 1
        queue = deque([])
        for course in range(numCourses):
            if indegrees[course] == 0:
                queue.append(course)
        
        # run bfs, getting each course with indegree 0, adding it to res, and
        # decrementing the indegree of all the courses it is a prereq for. if 
        # any of those indegrees reach 0, we add it to the queue to be processed.
        # at
        res = []
        while queue:
            curr = queue.popleft()
            res.append(curr)
            for course in graph[curr]:
                indegrees[course] -= 1
                if indegrees[course] == 0:
                    queue.append(course)
        return res if len(res) == numCourses else []