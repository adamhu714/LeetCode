# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.res = float("-inf")
        self.helper(root)
        return self.res
        
    def helper(self, root):
        leftMax = 0
        rightMax = 0
        if root.left:
            leftMax = max(0, self.helper(root.left))
        if root.right:
            rightMax = max(0, self.helper(root.right))
        self.res = max(self.res, leftMax + root.val + rightMax)
        return max(leftMax, rightMax) + root.val
    