# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        res = []

        def dfs(root, currSum):
            if root is None:
                return

            currSum += root.val

            if root.left is None and root.right is None:
                res.append(currSum)
                return

            dfs(root.left, currSum)
            dfs(root.right, currSum)

        dfs(root, 0)
        return targetSum in res
