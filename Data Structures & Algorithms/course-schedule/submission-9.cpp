class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, std::vector<int>> adj;
        unordered_map<int, int> remainings;

        for(auto prerequisite : prerequisites){
            int needed = prerequisite[1];
            int needs = prerequisite[0];
            remainings[needs]++;
            adj[needed].push_back(needs);
        }

        queue<int> q;
        int visited = 0;
        for(int i = 0 ; i < numCourses; i++){
            if (remainings[i] == 0) {
                q.push(i);
                visited++;
            }
        }
        while(q.size()){
            int current = q.front();
            q.pop();
            for(int course :  adj[current]){
                remainings[course]--;
                if (remainings[course] == 0){
                    q.push(course);
                    visited++;
                }
            }
        }
        return visited == numCourses;




        
    }
};
