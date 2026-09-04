class Solution:
    def findRedundantDirectedConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)

        root = [i for i in range(n + 1)]

        def find(x):
            if root[x] != x:
                root[x] = find(root[x])
            return root[x]

        def union(x, y):
            x, y = find(x), find(y)

            if x == y:
                return False

            root[x] = y
            return True

        parent = [0] * (n + 1)
        e1 = e2 = None

        for x, y in edges:
            if parent[y] != 0:
                e1 = [parent[y], y]
                e2 = [x, y]
                break

            parent[y] = x

        for x, y in edges:
            if e2 == [x, y]:
                continue

            if not union(x, y):
                return e1 or [x, y]

        return e2
