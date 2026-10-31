# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        if root is None:
            return True

        def validate(
            root: Optional[TreeNode], 
            minv: int, maxv: int
        ) -> bool:
            if root is None:
                return True
            else:
                return (minv < root.val < maxv and
                    validate(root.left, minv, root.val) and
                    validate(root.right, root.val, maxv))
        
        return validate(root.left, -float('inf'), root.val) and validate(root.right, root.val, float('inf'))