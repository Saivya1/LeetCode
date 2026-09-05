import heapq


class MedianFinder:

    def __init__(self):
        self.minHeap = []
        self.maxHeap = []

    def addNum(self, num: int) -> None:
        minHeap = self.minHeap
        maxHeap = self.maxHeap

        heapq.heappush(maxHeap, -num)

        delNum = -heapq.heappop(maxHeap)
        heapq.heappush(minHeap, delNum)

        if len(minHeap) > len(maxHeap):
            delNum = heapq.heappop(minHeap)
            heapq.heappush(maxHeap, -delNum)

    def findMedian(self) -> float:
        minHeap = self.minHeap
        maxHeap = self.maxHeap

        if len(maxHeap) > len(minHeap):
            return -maxHeap[0]

        return (-maxHeap[0] + minHeap[0]) / 2
