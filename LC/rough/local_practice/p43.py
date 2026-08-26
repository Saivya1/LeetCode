# Definition for a Node.
class Node:
    def __init__(self, val=0, neighbors=None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []


from typing import Optional


class Solution:
    def cloneGraph(self, node: Optional["Node"]) -> Optional["Node"]:
        clones = dict()
        if node is None:
            return

        def dfs(node):
            if node in clones:
                return

            new_node = Node(node.val)
            clones[node] = new_node

            for neigh in node.neighbors:
                dfs(neigh)
                new_node.neighbors.append(clones[neigh])

        dfs(node)
        return clones[node]
