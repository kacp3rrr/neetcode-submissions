class Solution:
    def solve(self, board: List[List[str]]) -> None:
        NUM_ROWS, NUM_COLS = len(board), len(board[0])                   
        safe = set()
        # dfs helper
        def dfs(row: int, col: int) -> None:
            if (
                row < 0 or
                row >= NUM_ROWS or
                col < 0 or
                col >= NUM_COLS or
                board[row][col] == 'X' or
                (row, col) in safe
            ): 
                return
            safe.add((row, col))
            dfs(row + 1, col)
            dfs(row - 1, col)
            dfs(row, col + 1)
            dfs(row, col - 1)

        # dfs on all border O's, as whatever O's are attached to them are safe
        for row in range(NUM_ROWS):
            if board[row][0] == 'O':
                dfs(row, 0)
            if row in (0, NUM_ROWS - 1):
                for col in range(1, NUM_COLS - 1):
                    if board[row][col] == 'O':
                        dfs(row, col)
            if board[row][NUM_COLS - 1] == 'O':
                dfs(row, NUM_COLS - 1)
        
        # linear search to replace any O's not in safe with X's
        for row in range(NUM_ROWS):
            for col in range(NUM_COLS):
                if board[row][col] == 'O' and (row, col) not in safe:
                    board[row][col] = 'X'

