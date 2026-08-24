# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque


class Codec:

    def serialize(self, root: Optional[TreeNode]) -> str:
        data = []

        def dfs(node):
            if node is None:
                return

            data.append(str(node.val))
            dfs(node.left)
            dfs(node.right)

        dfs(root)
        return ",".join(data)

    def deserialize(self, data: str) -> Optional[TreeNode]:
        if not data:
            return None

        preorder = deque(map(int, data.split(",")))

        def reconstruct(low, high):
            if not preorder:
                return None

            val = preorder[0]

            if val < low or val > high:
                return None

            preorder.popleft()

            node = TreeNode(val)

            node.left = reconstruct(low, val)
            node.right = reconstruct(val, high)

            return node

        return reconstruct(float("-inf"), float("inf"))


# Your Codec object will be instantiated and called as such:
# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# tree = ser.serialize(root)
# ans = deser.deserialize(tree)
# return ans
