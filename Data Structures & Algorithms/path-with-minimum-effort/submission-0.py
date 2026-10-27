class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        NUM_ROWS, NUM_COLS = len(heights), len(heights[0])
        # make a 2d dist array that tracks the min effort to reach each cell
        effort = [[float('inf')] * NUM_COLS for _ in range(NUM_ROWS)]
        effort[0][0] = 0

        # minheap storing tuple of form (curr_effort, row, col)
        minheap = [(0,0,0)]
        dirs = [(-1,0), (1,0), (0,-1), (0, 1)]

        while minheap:
            curr_effort, row, col = heapq.heappop(minheap)

            # primary return condition. we will never exit the while loop
            # before returning. we must reach bottom right eventually
            if row == NUM_ROWS - 1 and col == NUM_COLS - 1:
                return curr_effort

            if curr_effort > effort[row][col]:
                continue
            
            for dr, dc in dirs:
                nr, nc = row + dr, col + dc

                if 0 <= nr < NUM_ROWS and 0 <= nc < NUM_COLS:
                    curr_jump = abs(heights[row][col] - heights[nr][nc])
                    next_effort = max(curr_effort, curr_jump)

                    if next_effort < effort[nr][nc]:
                        effort[nr][nc] = next_effort
                        heapq.heappush(minheap, (next_effort, nr, nc))

