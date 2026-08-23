# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        count = 0

        def dfs(node, path):
            nonlocal count
            if node is None:
                return

            path.append(node.val)

            if all(x <= node.val for x in path):
                count += 1

            dfs(node.left, path)
            dfs(node.right, path)

            path.pop()

        dfs(root, [])

        return count
