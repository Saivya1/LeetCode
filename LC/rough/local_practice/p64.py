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

            root[x] = y
            return True

        parent = [0 for _ in range(n + 1)]
        e1 = e2 = None
        for u, v in edges:
            if parent[v] != 0:
                e1, e2 = [parent[v], v], [u, v]
                break
            else:
                parent[v] = u

        for u, v in edges:
            if e2 == [u, v]:
                continue
            if not union(u, v):
                return e1 or [u, v]

        return e2
