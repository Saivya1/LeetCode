import heapq


class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        heap = []

        def calculateDist(x, y):
            x2 = 0
            y2 = 0
            a = (x - x2) ** 2 + (y - y2) ** 2
            return a

        for coordinates in points:
            heapq.heappush(
                heap,
                [
                    -calculateDist(coordinates[0], coordinates[1]),
                    [coordinates[0], coordinates[1]],
                ],
            )
            if len(heap) > k:
                heapq.heappop(heap)

        return [coord for _, coord in heap]
