class Solution:
    def findOrder(self, numCourses: int, prerequisites: list[list[int]]) -> List[int]:
        adjList = [[] for _ in range(numCourses)]
        visited = [False] * numCourses
        onPath = [False] * numCourses
        order = []

        for pre in prerequisites:
            adjList[pre[1]].append(pre[0])

        def hasCycle(course):
            visited[course] = True
            onPath[course] = True

            for neigh in adjList[course]:
                if not visited[neigh]:
                    if hasCycle(neigh):
                        return True
                elif onPath[neigh]:
                    return True

            onPath[course] = False
            order.append(course)
            return False

        for i in range(numCourses):
            if not visited[i]:
                if hasCycle(i):
                    return []

        order.reverse()
        return order
