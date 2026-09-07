import heapq


class Solution:
    def findCheapestPrice(
        self, n: int, flights: List[List[int]], src: int, dst: int, k: int
    ) -> int:
        if src == dst:
            return 0
        heap = [(0, src, k + 1)]
        distance = [[float("inf")] * (k + 2) for _ in range(n)]
        adjList = [[] for _ in range(n)]

        for u, v, w in flights:
            adjList[u].append((v, w))

        while heap:
            currPrice, node, stops = heapq.heappop(heap)
            if node == dst:
                return currPrice

            if stops > 0:
                for v, w in adjList[node]:
                    newDist = currPrice + w
                    if newDist < distance[v][stops - 1]:
                        distance[v][stops - 1] = newDist
                        heapq.heappush(heap, (newDist, v, stops - 1))

        return -1
