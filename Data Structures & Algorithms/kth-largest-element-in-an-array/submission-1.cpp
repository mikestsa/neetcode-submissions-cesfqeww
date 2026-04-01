class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, std::vector<int>, greater<int>> heap;
        for(int num : nums){
            if (heap.size() < k){
            heap.push(num);
            }
            else if (heap.size() == k && heap.top() < num){
                heap.pop();
                heap.push(num);
            }
        }
        return heap.top();
        
    }
};
