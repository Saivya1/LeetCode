# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        count = 0
        maximum = root.val

        def dfs(root, maximum):
            nonlocal count
            if root is None:
                return

            if maximum <= root.val:
                count += 1

            maximum = max(root.val, maximum)

            dfs(root.left, maximum)
            dfs(root.right, maximum)

        dfs(root, maximum)

        return count
