from collections import defaultdict
import heapq


class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        dict = defaultdict(list)
        res = []
        for u, v in tickets:
            heapq.heappush(dict[u], v)

        def dfs(start):
            while dict[start]:
                dst = heapq.heappop(dict[start])
                dfs(dst)

            res.append(start)

        dfs("JFK")
        return res[::-1]
