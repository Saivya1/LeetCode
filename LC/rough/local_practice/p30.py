# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        ans = []

        def dfs(node, currSum, path):
            if node is None:
                return

            currSum += node.val
            path.append(node.val)

            if node.left is None and node.right is None:
                if currSum == targetSum:
                    ans.append(path.copy())
                path.pop()
                return

            dfs(node.left, currSum, path)
            dfs(node.right, currSum, path)

            path.pop()

        dfs(root, currSum=0, path=[])

        return ans
