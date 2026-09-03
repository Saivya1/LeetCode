class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        maxSum = float("-inf")

        def pathSum(root):
            nonlocal maxSum

            if root is None:
                return 0

            left = max(0, pathSum(root.left))
            right = max(0, pathSum(root.right))

            currSum = left + right + root.val
            maxSum = max(maxSum, currSum)

            return root.val + max(left, right)

        pathSum(root)
        return maxSum
