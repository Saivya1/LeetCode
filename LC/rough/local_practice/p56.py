# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        res = []
        currSum = 0
        currPath = []

        def dfs(root, currSum, currPath):
            if root is None:
                return

            currPath.append(root.val)
            currSum += root.val

            if root.left is None and root.right is None:
                if currSum == targetSum:
                    res.append(currPath.copy())

            dfs(root.left, currSum, currPath)
            dfs(root.right, currSum, currPath)
            currPath.pop()

        dfs(root, currSum, currPath)
        return res
