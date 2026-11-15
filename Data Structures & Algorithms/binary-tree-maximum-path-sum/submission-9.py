# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        maxSum = -float('inf')
        def findMaxSum(node: Optional[TreeNode]) -> int:
            nonlocal maxSum
            if not node:
                return 0
            leftSum = findMaxSum(node.left)
            rightSum = findMaxSum(node.right)
            currMaxSum = max(
                node.val,
                node.val + leftSum, 
                node.val + rightSum,
            )
            maxSum = max(maxSum, currMaxSum, node.val + leftSum + rightSum)
            return currMaxSum
        findMaxSum(root)
        return maxSum
            