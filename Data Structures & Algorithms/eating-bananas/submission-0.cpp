class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // find the upper bound for the rate, which is the largest pile
        int upper = 0;
        for (int p : piles) {
            if (p > upper) upper = p;
        }
        // the absolute minimum rate would be 1 banana per hour
        int lower = 1;
        // do a binary search on the upper and low bounds until they intersect, 
        // and for each, determine if the middle value for k (upper+lower/2) takes more
        // than h hours. if it does, then cut off the left half. If it doesnt, cut off the
        // right half. Continue until you land on the smallest possible value
        while (lower != upper) {
            int currentRate = ((upper + lower) / 2);
            int totalHourCount = 0;
            for (int p : piles) { // add the number of hours it would take to eat each pile
                totalHourCount += ceil(p / (currentRate * 1.0));
            }
            if (totalHourCount > h) {
                lower = currentRate + 1;
            } else {
                upper = currentRate;
            }
        }
        return upper;
    }
};
