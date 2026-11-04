class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: (x[1], x[0]))
        nonOverlapping = 0
        currEnd = intervals[0][1]
        for i in range(1, len(intervals)):
            if intervals[i][0] >= currEnd:
                nonOverlapping += 1
                currEnd = intervals[i][1]
        return len(intervals) - nonOverlapping - 1