class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // sort cars by descending order - {position, index}
        vector<pair<int, int>> sortedPositions;
        for (int i = 0; i < position.size(); ++i) {
            sortedPositions.push_back({position[i], i});
        }
        sort(sortedPositions.begin(), sortedPositions.end(), greater<pair<int, int>>());
        // maintain a stack of fleet arrival times. if the car behind it arrives sooner than the
        // one in front, it will merge into that fleet. otherwise, that car gets pushed as its own
        // fleet.
        stack<double> arrivalTimes;
        for (int i = 0; i < sortedPositions.size(); ++i) {
            int currentIndex = sortedPositions[i].second;
            int currentPosition = sortedPositions[i].first;
            int currentSpeed = speed[currentIndex];
            double arrivalTime = (target - currentPosition) / (currentSpeed * 1.0);
            cout << arrivalTime << endl;
            if (arrivalTimes.empty()) {
                arrivalTimes.push(arrivalTime);
            } else if (arrivalTimes.top() < arrivalTime) { // not <= since cars that meet at the end are a fleet
                arrivalTimes.push(arrivalTime);
            }
        }
        return arrivalTimes.size();
    }
};
