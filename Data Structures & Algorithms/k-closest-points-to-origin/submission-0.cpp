class Solution {
private:
    // helper to calculate euclidean distance from origin
    double distToOrigin(const vector<int>& p) {
        return sqrt((p[0] * p[0]) + (p[1] * p[1]));
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [this](const vector<int>& a, const vector<int>& b) {
            return distToOrigin(a) < distToOrigin(b);
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> k_closest(cmp);
        for (const vector<int>& p : points) {
            k_closest.push(p);
            if (k_closest.size() > k) {
                k_closest.pop();
            }
        }
        vector<vector<int>> res;
        while (!k_closest.empty()) {
            res.push_back(k_closest.top());
            k_closest.pop();
        }
        return res;
    }
};
