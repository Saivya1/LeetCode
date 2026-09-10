class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        starts = sorted(x[0] for x in intervals)
        ends = sorted(x[1] for x in intervals)

        room = 0
        end = 0

        for start in starts:
            if start < ends[end]:
                room += 1
            else:
                end += 1

        return room
