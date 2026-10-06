class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        INF = 2**31 - 1
        NUM_ROWS, NUM_COLS = len(grid), len(grid[0])
        queue = deque([])

        # multi-source bfs initial populate
        for row in range(NUM_ROWS):
            for col in range(NUM_COLS):
                if grid[row][col] == 0:
                    queue.append((row, col, 0))
        
        # run bfs starting from all the treasure points, go outwards until
        # we've covered all possible land values that are reachable
        while queue:
            row, col, dist = queue.popleft()
            if (
                row < 0 or
                row >= NUM_ROWS or
                col < 0 or
                col >= NUM_COLS or
                (dist > 0 and grid[row][col] != INF)
            ):
                continue
            grid[row][col] = dist # implicitly sets the treasure chest to 0, so we can just keep this
            queue.append((row + 1, col, dist + 1))
            queue.append((row - 1, col, dist + 1))
            queue.append((row, col + 1, dist + 1))
            queue.append((row, col - 1, dist + 1))
        
