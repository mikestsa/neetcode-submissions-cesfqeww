class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> out;
        unordered_map<int, std::vector<int>> adj;
        unordered_map<int, int> remaining;

        for(auto prerequisite : prerequisites){
            int needed = prerequisite[1];
            int needs = prerequisite[0];
            remaining[needs]++;
            adj[needed].push_back(needs);
        }
        std::queue<int> q;
        for(int i = 0 ; i < numCourses ; i++){
            if (remaining[i] == 0){
                q.push(i);
            }
        }

        while(q.size()){
            int current = q.front();
            q.pop();
            out.push_back(current);
            for(int course : adj[current]){
                remaining[course]--;
                if (remaining[course] == 0) q.push(course);
            }
        }
        if (out.size() == numCourses) return out;
        return {};
        
    }
};
