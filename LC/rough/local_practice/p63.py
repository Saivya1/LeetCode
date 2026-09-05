class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals = sorted(intervals)
        res = []

        for interval in intervals:
            if not res or interval[0] > res[-1][1]:
                res.append(interval)
            if interval[0] <= res[-1][1]:
                res[-1][1] = max(res[-1][1], interval[1])

        return res
