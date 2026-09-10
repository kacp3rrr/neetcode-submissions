class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort intervals by lower bound. if they are equal, sort by upper bound
        sort(intervals.begin(), intervals.end(),
            [](const vector<int>& a, const vector<int>& b) {
                if (a[0] == b[0]) {
                    return a[1] < b[1];
                } else {
                    return a[0] < b[0];
                }
            });
        // for each interval starting from the left, we can merge it if the lower bound of the current
        // falls within the range of the previous interval (since they are sorted by lower bound, this
        // just means checking whether it is less than the upper bound)
        vector<vector<int>> merged;
        // add the first interval as the mostRecentInterval
        vector<int> mostRecentInterval = {intervals[0][0], intervals[0][1]};
        for (int i = 1; i < intervals.size(); ++i) {
            vector<int> curr = intervals[i];
            // if the current interval overlaps with the one previous, then merge it with that one
            // otherwise, push the most recent merged interval into the vector of merged intervals, and
            // make the current interval the mostRecentInterval
            if (curr[0] <= mostRecentInterval[1]) {
                mostRecentInterval[1] = max(curr[1], mostRecentInterval[1]);
            } else {
                merged.push_back(mostRecentInterval);
                mostRecentInterval = curr;
            }
        }
        // append the last interval and return
        merged.push_back(mostRecentInterval);
        return merged;
    }
};
