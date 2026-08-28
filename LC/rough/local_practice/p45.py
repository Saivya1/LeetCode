class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        color = [-1] * len(graph)

        def dfs(node, curr_color):
            color[node] = curr_color

            for neigh in graph[node]:
                if color[neigh] == -1:
                    if not dfs(neigh, 1 - curr_color):
                        return False
                elif color[neigh] == curr_color:
                    return False

            return True

        for i in range(len(graph)):
            if color[i] == -1:
                if not dfs(i, 0):
                    return False

        return True
