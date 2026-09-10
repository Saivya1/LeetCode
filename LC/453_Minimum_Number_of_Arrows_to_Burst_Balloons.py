class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort()
        end = points[0][1]
        res = len(points)

        for i in range(1, len(points)):
            if points[i][0] <= end:
                res -= 1
                end = min(end, points[i][1])
            else:
                end = points[i][1]

        return res
