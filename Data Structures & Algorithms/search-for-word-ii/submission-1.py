class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        # build trie
        trie = {}
        for word in words:
            node = trie
            for ch in word:
                if ch not in node:
                    node[ch] = {}
                
                node = node[ch]
            node['#'] = word

        # run dfs on the board, passing a node representing where we currently are in the trie
        res = []
        NUMROWS, NUMCOLS = len(board), len(board[0])
        def dfs(row, col, node) -> bool: 
            if (
                row < 0 or
                row >= NUMROWS or
                col < 0 or
                col >= NUMCOLS or
                board[row][col] not in node
            ):
                return 
            
            char = board[row][col]
            node = node[char]
            
            # pop the terminal marker to avoid duplicate pushes
            if '#' in node:
                res.append(node.pop('#'))
            
            # mark with some non-alphabetic character before recursive call to avoid
            # false revisits
            board[row][col] = "$"
            
            for dr, dc in [(1,0), (-1,0), (0,1), (0,-1)]:
                dfs(row + dr, col + dc, node)
            
            # restore what we did above
            board[row][col] = char

        # run dfs at each letter. on the first iteration of dfs, on a letter that doesnt start
        # any word, dfs exits, so the trie avoids exploring paths that arent prefixes of any word
        for i in range(NUMROWS):
            for j in range(NUMCOLS):
                dfs(i, j, trie)

        return res
