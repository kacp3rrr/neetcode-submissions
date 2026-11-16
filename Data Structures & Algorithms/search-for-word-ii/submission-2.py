class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        M, N = len(board), len(board[0])
        trie = {}
        res = []
        for word in words:
            curr = trie
            for ch in word:
                if ch not in curr:
                    curr[ch] = {}
                
                curr = curr[ch]
            curr['#'] = word # use "#" as a terminator, and have it point to the word


        # dfs from row, col, and the current node we're at in the trie (the whole trie being a base case)
        dirs = [(-1,0), (1,0), (0,-1), (0,1)]
        def dfs(r, c, node):
            if (
                not (0 <= r < M) or
                not (0 <= c < N) or 
                board[r][c] not in node
            ):
                return
            curr = board[r][c]
            node = node[curr]
            if '#' in node:
                res.append(node.pop('#'))
            
            # avoid retraversing paths on local dfs calls
            board[r][c] = "!"

            for dr, dc in dirs:
                nr, nc = r+dr, c+dc
                dfs(nr,nc, node)
            
            # allow retraversing of the path
            board[r][c] = curr
        
        for i in range(M):
            for j in range(N):
                dfs(i,j,trie)
        
        return res
