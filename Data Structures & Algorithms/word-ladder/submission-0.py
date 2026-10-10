class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        """
        initial idea: shortest path bfs traversal, map out a graph in a way that represents
        word connections
        """
        if endWord not in wordList or len(beginWord) != len(endWord) or beginWord == endWord:
            return 0
        
        # populate graph of patterns
        graph = defaultdict(list)
        for word in wordList:
            for i in range(len(word)):
                # we can create a pattern (e.g., c_t) as a key in the graph, and its value is a 
                # list of all words that fit this pattern
                pattern = word[:i] + "_" + word[i+1:]
                graph[pattern].append(word)
        
        # run bfs on this pattern set, where the number of levels before our first hit on endWord
        # is the minimum number of words within the transformation sequence. if we finish bfs
        # without returning, then endWord is unreachable from beginWord, so we return 0
        seen = set()
        queue = deque([(beginWord, 1)]) # set of word with level
        # figure out level tracking
        while queue:
            curr, level = queue.popleft()
            seen.add(curr)
            for i in range(len(curr)):
                currPattern = curr[:i] + "_" + curr[i+1:]
                for match in graph[currPattern]:
                    if match in seen:
                        continue
                    if match == endWord:
                        return level + 1
                    queue.append((match, level + 1))
        return 0
        

