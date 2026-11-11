"""
# Definition for a Node.
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.parent = None
"""

class Solution:
    def lowestCommonAncestor(self, p: 'Node', q: 'Node') -> 'Node':
        # have both paths from p and q race side by side to the top, store each node in
        # seen set. whichever duplicate is found first is the LCA
        seen = set()
        left, right = p, q
        while left or right:
            if left == right:
                return left
            elif left and left in seen:
                return left
            elif right and right in seen:
                return right
            else:
                seen.add(left)
                seen.add(right)
                if left:
                    left = left.parent
                if right:
                    right = right.parent
