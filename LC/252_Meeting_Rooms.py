class Solution:
    def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
        if not intervals:
            return True

        intervals.sort()
        end = intervals[0][1]

        for i in range(1, len(intervals)):
            if intervals[i][0] < end:
                return False
            else:
                end = intervals[i][1]

        return True
