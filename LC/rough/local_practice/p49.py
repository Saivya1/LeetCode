# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:

        def checkRange(root, low, high):
            if root is None:
                return True
            if root.val <= low:
                return False
            if root.val >= high:
                return False

            left = checkRange(root.left, low, root.val)
            right = checkRange(root.right, root.val, high)

            return left and right

        return checkRange(root, float("-inf"), float("inf"))
