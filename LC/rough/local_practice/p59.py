# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        inorder = []
        if root is None:
            return -1

        def dfs(root):
            if root is None:
                return

            dfs(root.left)
            inorder.append(root.val)
            dfs(root.right)

        dfs(root)
        return inorder[k - 1]
