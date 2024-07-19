# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if p.val < q.val:
            low = p
            high = q
        else:
            low = q
            high = p
        
        if root.val >= low.val and root.val <= high.val:
            return root
        
        if root.val > high.val:
            return self.lowestCommonAncestor(root.left, low, high)
        return self.lowestCommonAncestor(root.right, low, high)