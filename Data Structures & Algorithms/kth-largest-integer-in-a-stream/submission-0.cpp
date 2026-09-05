class KthLargest {
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> stream;
public:
    KthLargest(int k, vector<int>& nums) : k{k} {
        for (int val : nums) {
            add(val);
        }
    }
    int add(int val) {
        stream.push(val);
        if (stream.size() > k) {
            stream.pop();
        }
        return stream.top();
    }
};
