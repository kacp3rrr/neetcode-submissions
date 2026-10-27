class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n + 1, INT_MAX); // n+1 just to not have to deal with adjusting for 0 indexing, since nodes are 1 to n. 
        dist[0] = 0; // as mentioned above, this wont be touched
        dist[k] = 0;
        // min heap of pairs in form (dist, node)
        priority_queue<pair<int, int>, 
                    vector<pair<int, int>>, 
                    greater<pair<int,int>>> minheap;
        minheap.push({0, k});

        while (!minheap.empty()) {
            auto [currDist, currNode] = minheap.top();
            minheap.pop();
            if (currDist > dist[currNode]) continue;
            for (const vector<int>& t : times) {
                int u = t[0], v = t[1], time = t[2];
                if (u != currNode) continue;
                if (dist[u] + time < dist[v]) {
                    dist[v] = dist[u] + time;
                    minheap.push({dist[v], v});
                }
            }
        }
        
        // find and return max distance
        int maximum = -1;
        for (const int& n : dist) {
            maximum = max(maximum, n);
        }
        return maximum == INT_MAX ? -1 : maximum;
    }
};
