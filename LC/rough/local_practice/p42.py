class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        parent = [i for i in range(1, len(edges) + 1)]

        def find(x):
            if parent[x - 1] != x:
                parent[x - 1] = find(parent[x - 1])
            return parent[x - 1]

        def union(x, y):
            x = find(x)
            y = find(y)

            if x == y:
                return False

            parent[y - 1] = x
            return True

        for x, y in edges:
            if not union(x, y):
                return [x, y]

        return []
