import heapq


class Solution:
    def findCheapestPrice(
        self, n: int, flights: List[List[int]], src: int, dst: int, k: int
    ) -> int:
        adjList = [[] for _ in range(n)]
        for u, v, w in flights:
            adjList[u].append((v, w))
        heap = [(0, src, k + 1)]
        distance = [[float("inf")] * (k + 2) for _ in range(n)]

        while heap:
            currW, node, stops = heapq.heappop(heap)

            if node == dst:
                return currW

            if stops > 0:
                for v, w in adjList[node]:
                    newDist = w + currW
                    if newDist < distance[v][stops - 1]:
                        distance[v][stops - 1] = newDist
                        heapq.heappush(heap, (newDist, v, stops - 1))

        return -1
