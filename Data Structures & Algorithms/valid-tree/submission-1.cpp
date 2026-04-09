class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.empty()) return true;
        if (edges.size() + 1 != n) return false;
        unordered_map<int, std::vector<int>> m;
        for(auto edge : edges){
            m[edge[0]].push_back(edge[1]);
            m[edge[1]].push_back(edge[0]);
        }
        std::unordered_set<int> visited;
        for(int i = 0 ; i < n ; i++){
            if (m[i].empty()) return false;
            if (visited.find(i) == visited.end()){
                if (hasCycle(i, -1, visited, m)) return false;
            }
        }
        return true;

    }

    bool hasCycle(int i, int previous, std::unordered_set<int>& visited, unordered_map<int, std::vector<int>>& edges  ){
        visited.insert(i);
        for(int neib : edges[i]){
            if (neib == previous) continue;
            if (visited.find(neib) != visited.end()) return true;
            if (hasCycle(neib, i, visited, edges)) return true;
        }
        return false;

    }
};
