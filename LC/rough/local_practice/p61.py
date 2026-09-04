class Solution:
    def findRedundantDirectedConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)
        root = [i for i in range(n + 1)]

        def find(x):
            if root[x] != x:
                root[x] = find(root[x])
            return root[x]

        def union(x, y):
            x = find(x)
            y = find(y)

            if x == y:
                return False

            root[y] = x
            return True

        parent = [0 for _ in range(n + 1)]
        e1 = e2 = None

        for x, y in edges:
            if parent[y] != 0:
                e1, e2 = [parent[y], y], [x, y]
                break
            parent[y] = x

        for x, y in edges:
            if [x, y] == e2:
                continue
            if not union(x, y):
                return e1 or [x, y]

        return e2
