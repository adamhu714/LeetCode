# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        def dfs(node):
            if node == None:
                return 0
            else: 
                return max(dfs(node.left) + 1, dfs(node.right) + 1)
        return dfs(root)
            # maxLength = 0
            # if node.left == None and node.right == None:
            #     return 1
            # elif node.left == None:
            #     return dfs(node.right) + 1
            # elif node.right == None:
            #     return dfs(node.left) + 1
            