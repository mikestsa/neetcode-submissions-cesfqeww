class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, std::vector<std::pair<int,int>>> from_to_time;
        for(auto time : times){
            from_to_time[time[0]].push_back({time[1], time[2]});
        }
        int ret_time = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        minHeap.push({0,k});
        unordered_set<int> visited;
        visited.insert(k);
        int rettime = 0;
        while(minHeap.size()){
            auto [time, node] = minHeap.top();
            minHeap.pop();
                visited.insert(node);
            if (visited.size() == n) return time;

            for(auto [neib, neib_time] : from_to_time[node]){
                if (visited.find(neib) != visited.end()) continue;
                minHeap.push({time + neib_time, neib});
            }


        }
        return -1;
    }
};
