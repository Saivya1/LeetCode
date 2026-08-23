# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        def dfs(self, root, targetSum, currSum):
            if root is None:
                return

            currSum += root.val

            if root.left is None and root.right is None:
                if currSum == targetSum:
                    return True
                return

            dfs(self, root.left, targetSum, currSum)
            dfs(self, root.right, targetSum, currSum)

        has = dfs(self, root, targetSum, 0)

        return has is True
