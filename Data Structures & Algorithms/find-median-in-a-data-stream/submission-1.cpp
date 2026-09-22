class MedianFinder {
private:
    // maxHeap holds the lower half of elements in the datastream, minHeap
    // holds the upper half.
    priority_queue<int, vector<int>, less<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    double median;
public:
    MedianFinder() {}
    
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        // rebalance the two heaps (they will either be even size or minHeap will be greater by one)
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        // compute median
        int maxTop = maxHeap.empty() ? 0 : maxHeap.top();
        int minTop = minHeap.empty() ? 0 : minHeap.top();
        if (maxHeap.size() == minHeap.size()) {
            median = (1.0 * (maxTop+ minTop) / 2);
        } else {
            median = maxTop * 1.0;
        }
    }
    
    double findMedian() {
        return median;
    }
};
