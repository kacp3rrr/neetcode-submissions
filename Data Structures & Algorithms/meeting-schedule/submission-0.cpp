/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        // sort by start times
        sort(intervals.begin(), intervals.end(), 
            [](const Interval& a, const Interval& b) {
                return a.start < b.start;
            });
        // for each interval, see if the meeting previous ends after the current one starts
        // and return false if so
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i-1].end > intervals[i].start) {
                return false;
            }
        }
        return true;
    }
};
