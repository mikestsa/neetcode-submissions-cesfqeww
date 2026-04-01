class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int minHeapSize = minHeap.size();
        int maxHeapSize = maxHeap.size();
        if (minHeapSize < maxHeapSize){
            minHeap.push(num);
        }
        else maxHeap.push(num);
                    
        if (minHeap.size() && minHeap.top() < maxHeap.top()){
            minHeap.push(maxHeap.top());
            maxHeap.push(minHeap.top());
            minHeap.pop();
            maxHeap.pop();
        }
        
    }
    
    double findMedian() {
        int minHeapSize = minHeap.size();
        int maxHeapSize = maxHeap.size();
        if ((maxHeapSize + minHeapSize)%2) return maxHeap.top();
        return (minHeap.top() + maxHeap.top())*0.5;

  
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */