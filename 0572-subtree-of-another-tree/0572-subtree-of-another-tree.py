# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if not root or not subRoot:
            return root == subRoot
        
        if root.val == subRoot.val:
            if self.isSame(root, subRoot):
                return True
        
        return self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)
        
        
    def isSame(self, t1, t2):
        if not t1 or not t2:
            if t1 == t2:
                return True
            return False
        if t1.val != t2.val:
            return False
        return self.isSame(t1.left, t2.left) and self.isSame(t1.right, t2.right)