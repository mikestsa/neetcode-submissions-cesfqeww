class Solution {
    unordered_map<int, std::vector<int>> preMap;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        preMap.clear();
        for(auto pre : prerequisites ){
            preMap[pre[0]].push_back(pre[1]);
        }
        for(int i = 0 ; i < numCourses; i++){
            std::unordered_set<int> visited;
            if (cycleExistsStartingFrom(i, visited)) return false;
        }

        return true;
        
    }

    bool cycleExistsStartingFrom(int from, std::unordered_set<int> &visited){
        if (visited.count(from)) return true;

        visited.insert(from);

        for(auto neib : preMap[from]){
            if (cycleExistsStartingFrom(neib, visited)) return true;
        }

        visited.erase(from);
        preMap[from].clear();

        return false;


    }


};
