class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        parent = [i for i in range(n)]
        numGrp = n

        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]

        def union(x, y):
            x = find(x)
            y = find(y)

            if x == y:
                return False

            parent[y] = x

            return True

        for x, y in edges:
            if union(x, y):
                numGrp -= 1

        return numGrp
