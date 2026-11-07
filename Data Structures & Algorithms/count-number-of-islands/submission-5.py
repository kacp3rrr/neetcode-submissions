

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:

        num_islands = 0
        discovered: Set[tuple[int, int]] = set()

        def traverse_island(y: int, x: int):
            # mark y, x as discovered
            discovered.add((y, x))
            # loop through direct neighbors 
            for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                neighbor_y, neighbor_x = y+dr, x+dc

                if (neighbor_y, neighbor_x) in discovered:
                    continue

                # skip if neighbor is out of bounds
                if neighbor_y < 0 or neighbor_y + 1 > len(grid) or neighbor_x < 0 or neighbor_x + 1 > len(grid[neighbor_y]):
                    continue

                # skip if neighbor is water
                if grid[neighbor_y][neighbor_x] == "0":
                    continue
                
                traverse_island(neighbor_y, neighbor_x)
            pass

        for y in range(len(grid)):
            for x in range(len(grid[y])):

                current = grid[y][x]
                current_coords = (y, x)
                if current == "1":
                    # skip if discovered
                    if current_coords in discovered:
                        continue
                    
                    traverse_island(y, x)
                    num_islands += 1

                pass
        return num_islands

