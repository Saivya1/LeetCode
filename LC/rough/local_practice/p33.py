# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque


class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        um = {}
        queue = deque(preorder)

        for i in range(len(inorder)):
            um[inorder[i]] = i

        def dfs(left, right):
            if left > right:
                return None
            val = queue.popleft()
            node = TreeNode(val)

            node.left = dfs(left, um[val] - 1)
            node.right = dfs(um[val] + 1, right)

            return node

        return dfs(0, len(preorder) - 1)
