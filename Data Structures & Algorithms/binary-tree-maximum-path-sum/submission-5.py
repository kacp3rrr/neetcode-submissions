# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        maxSum = -float('inf')
        def dfs(node: Optional[TreeNode]) -> int:
            nonlocal maxSum
            if node is None:
                return 0
            leftSum, rightSum = max(dfs(node.left), 0), max(dfs(node.right), 0)
            currSum = leftSum + rightSum + node.val
            maxSum = max(maxSum, currSum)
            return node.val + max(leftSum, rightSum)
        dfs(root)
        return maxSum

                