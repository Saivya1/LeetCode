import heapq


class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        adjList = [[] for _ in range(n + 1)]

        for u, v, w in times:
            adjList[u].append((v, w))

        minheap = [(0, k)]
        visited = set()
        maxTime = 0

        while minheap:
            currTime, node = heapq.heappop(minheap)

            if node in visited:
                continue

            visited.add(node)
            maxTime = currTime

            for neigh, weight in adjList[node]:
                if neigh not in visited:
                    heapq.heappush(minheap, (currTime + weight, neigh))

        return maxTime if len(visited) == n else -1
