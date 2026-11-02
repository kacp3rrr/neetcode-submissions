class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        # dp[i][j] representing the minimum number of changes to make the
        # first i characters of word1 into the first j characters of word2
        n1, n2 = len(word1), len(word2)
        dp = [[0 for _ in range(n2+1)] for _ in range(n1+1)]
        
        # we populate the first row and column by an incrementing order, as, 
        # to get to a word from the first 0 characters of another, it is just
        # a sequence of insert operations
        for i in range(n1+1):
            for j in range(n2+1):
                if i != 0 and j != 0:
                    break; # only do first row in full, and first col of rest
                dp[i][j] = j if i == 0 else i
        
        # now go through the word 2-dimensionally, considering in each step the
        # cost of forming the first j letters of word2 from the first i letters 
        # of word1
        for i in range(1,n1+1):
            for j in range(1,n2+1):
                # if the first i-1 and j-1 characters are the exact same, the 
                # added cost is 0, so we just borrow from the cost to get to
                # that point. Otherwise, we set the cost to 1 + the minimum cost
                # to either delete, replace, or insert
                if word1[i-1] == word2[j-1]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    dp[i][j] = 1 + min(
                        dp[i-1][j],
                        dp[i][j-1],
                        dp[i-1][j-1]
                    )
        
        return dp[n1][n2]