class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort(key = lambda x: (x[1], x[0]))
        numArrows = 1
        currOverlapStart, currOverlapEnd = points[0][1], float('inf')
        for i in range(len(points) - 1):
            currOverlapStart = max(currOverlapStart, points[i+1][0])
            currOverlapEnd = min(currOverlapEnd, points[i][1])
            if currOverlapStart > currOverlapEnd:
                numArrows += 1
                currOverlapStart, currOverlapEnd = points[i][1], float('inf')
        
        return numArrows
            

        