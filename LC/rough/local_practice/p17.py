class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        return self.check(root, float("-inf"), float("inf"))

    def check(self, root, low, high):
        if root is None:
            return True

        if root.val <= low or root.val >= high:
            return False

        return self.check(root.left, low, root.val) and self.check(
            root.right, root.val, high
        )
