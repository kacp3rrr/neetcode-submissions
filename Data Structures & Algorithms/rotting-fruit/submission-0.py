class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        # initializing
        NUM_ROWS = len(grid)
        NUM_COLS = len(grid[0])
        queue = deque([])
        seen = set()
        res = 0
        fresh_oranges = 0

        # add all the initially rotten fruit to the queue
        for row in range(NUM_ROWS):
            for col in range(NUM_COLS):
                if grid[row][col] == 2:
                    queue.append((row, col))
                elif grid[row][col] == 1:
                    fresh_oranges += 1
        
        if fresh_oranges == 0:
            return 0

        # run bfs with the initially rotten fruit first, then processing all the fruit until we've
        # processed all fruit, keeping track of levels in stages 
        while queue and fresh_oranges > 0:
            res += 1
            level_size = len(queue)
            for _ in range(level_size):
                row, col = queue.popleft()

                for dr, dc in [(1,0), (-1,0), (0,1), (0,-1)]:
                    new_row, new_col = row + dr, col +dc
                    if (0 <= new_row < NUM_ROWS and
                        0 <= new_col < NUM_COLS and
                        grid[new_row][new_col] == 1):
                        grid[new_row][new_col] = 2
                        fresh_oranges -= 1
                        queue.append((new_row, new_col))

        return res if fresh_oranges == 0 else -1

