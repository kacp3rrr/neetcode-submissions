class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        start, end = newInterval
        index = 0
        while index < len(intervals) and intervals[index][0] < start:
            index += 1
        intervals.insert(index, newInterval)
        i = 0
        while i < len(intervals) - 1:
            (firstStart, firstEnd), (secondStart, secondEnd) = intervals[i], intervals[i+1]
            if not firstEnd < secondStart:
                intervals[i] = [firstStart, max(firstEnd, secondEnd)]
                intervals.pop(i+1)
            else:
                i += 1
        return intervals