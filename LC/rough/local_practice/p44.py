class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adjList = [[] for _ in range(numCourses)]
        res = []

        for pre in prerequisites:
            adjList[pre[1]].append(pre[0])

        visited = [False] * numCourses
        OnPath = [False] * numCourses

        def hasCyle(node):
            visited[node] = True
            OnPath[node] = True

            for neigh in adjList[node]:
                if not visited[neigh]:
                    if hasCyle(neigh):
                        return True
                elif OnPath[neigh]:
                    return True

            OnPath[node] = False
            res.append(node)
            return False

        for i in range(numCourses):
            if not visited[i]:
                if hasCyle(i):
                    return False

        res.reverse
        return res
