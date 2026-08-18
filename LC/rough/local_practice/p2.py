class Solution:
    def findOrder(self, numCourses: int, prerequisites: list[list[int]]) -> List[int]:
        adjlist = [[] for _ in range(numCourses)]
        order = []
        for pre in prerequisites:
            adjlist[pre[1]].append(pre[0])
        visited = [False] * numCourses
        onPath = [False] * numCourses

        for node in range(numCourses):
            if not visited[node]:
                if self.hasCycle(node, visited, onPath, adjlist, order):
                    return []

        return order[::-1]

    def hasCycle(self, node, visited, onPath, adjlist, order):
        visited[node] = True
        onPath[node] = True

        for neigh in adjlist[node]:
            if not visited[neigh]:
                if self.hasCycle(neigh, visited, onPath, adjlist, order):
                    return True

            elif onPath[neigh]:
                return True

        onPath[node] = False
        order.append(node)
        return False
