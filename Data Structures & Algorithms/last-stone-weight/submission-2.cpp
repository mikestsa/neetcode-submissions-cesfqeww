class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap;
        for(int stone : stones) heap.push(stone);
        while(heap.size() > 1){
            int stone1 = heap.top();
            heap.pop();
            int stone2 = heap.top();
            heap.pop();
            if (int res = abs(stone1 - stone2)) heap.push(res);
        }
        if (heap.size())return heap.top();
        return 0;
    }
};
