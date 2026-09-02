class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        res = []
        currPath = []
        currSum = 0

        def dfs(root, currSum, currPath):
            if root is None:
                return None

            currSum += root.val
            currPath.append(root.val)

            if root.left is None and root.right is None:
                if currSum == targetSum:
                    res.append(currPath.copy())

            dfs(root.left, currSum, currPath)
            dfs(root.right, currSum, currPath)

            currPath.pop()

        dfs(root, currSum, currPath)
        return res
