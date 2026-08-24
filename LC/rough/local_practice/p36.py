# Definition for a Node.
class Node:
    def __init__(self, val=0, neighbors=None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []


from typing import Optional


class Solution:
    def cloneGraph(self, node: Optional["Node"]) -> Optional["Node"]:
        if node is None:
            return None
        clones = {}

        def clone(node):
            if node is None:
                return None

            if node in clones:
                return clones[node]

            new_node = Node(node.val)
            clones[node] = new_node

            for neigh in node.neighbors:
                new_node.neighbors.append(clone(neigh))

            return new_node

        return clone(node)
