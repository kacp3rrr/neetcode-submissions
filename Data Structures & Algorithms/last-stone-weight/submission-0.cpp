class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // populate pqueue
        std::priority_queue<int, vector<int>> heaviest(stones.begin(), stones.end());
        // continually run condition until 1 or 0 stones.
        while(heaviest.size() > 1) {
            int x = heaviest.top();
            heaviest.pop();
            int y = heaviest.top();
            heaviest.pop();
            if (y < x) {
                x = x - y;
                heaviest.push(x);
            }
        }
        return (heaviest.size() > 0) ? heaviest.top() : 0;
    }
};
