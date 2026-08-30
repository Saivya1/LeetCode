from collections import defaultdict


class Solution:
    def numBusesToDestination(
        self, routes: List[List[int]], source: int, target: int
    ) -> int:

        stopToBus = defaultdict(set)

        for i, route in enumerate(routes):
            for stop in route:
                stopToBus[stop].add(i)

        queue = [(source, 0)]
        visited = set([source])

        for stop, numBus in queue:
            if stop == target:
                return numBus

            for bus in stopToBus[stop]:
                for nextStop in routes[bus]:
                    if nextStop not in visited:
                        visited.add(nextStop)
                        queue.append((nextStop, numBus + 1))

                routes[bus] = []

        return -1
