class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> smallHeap;
    priority_queue<int, vector<int>, greater<int>> largeHeap;// τοπ τ μικροτερο
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (smallHeap.size() > largeHeap.size()){
            largeHeap.push(num);
        }
        else{
            smallHeap.push(num);
        }
        if (smallHeap.size() && largeHeap.size()){
            if (largeHeap.top() < smallHeap.top()){
                int num1 = largeHeap.top();
                int num2 = smallHeap.top();
                largeHeap.pop();
                smallHeap.pop();
                largeHeap.push(num2);
                smallHeap.push(num1);
            }
        }
        
    }
    
    double findMedian() {
        if (smallHeap.size() > largeHeap.size()) return smallHeap.top();
        return ((smallHeap.top() + largeHeap.top())/2.0);
        
    }
};
