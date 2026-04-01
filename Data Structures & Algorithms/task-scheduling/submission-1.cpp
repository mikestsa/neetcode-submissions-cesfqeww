class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> counter;
        int max = 0;
        for(auto task : tasks){
            counter[task]++;
            max = std::max(max, counter[task]);
        }
        int total = 0;
        for(auto [c, count] : counter){
            if (count == max) total++;
        }
        return std::max((int)tasks.size(),(n+1)*(max-1) + total);
        
    }
};
