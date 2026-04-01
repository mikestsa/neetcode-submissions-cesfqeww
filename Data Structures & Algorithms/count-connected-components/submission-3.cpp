class Solution {
public:
    vector<int> parents;
    vector<int> rank;

    int find(int a){
        while(a != parents[a]){
            parents[a] = parents[parents[a]];
            a = parents[a];
        }
        return a;
    }

    bool unionn(int left, int right){

    int parent_a = find(left);
    int parent_b = find(right);
    if (parent_a == parent_b) return false;
    if (rank[parent_a] < rank[parent_b]){
        parents[parent_a] = parent_b;
    }
    else if  (rank[parent_a] > rank[parent_b]){
        parents[parent_b] = parent_a;
    }
    else{
        parents[parent_a] = parent_b;
        rank[parent_b]++;
    }
    return true;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        parents.resize(n);
        rank.resize(n);
        for(int i = 0 ; i < n ; i++) parents[i] = i;
        int out = n;
        for(auto edge : edges) {
           if (!unionn(edge[0], edge[1]));
        }
        unordered_set<int> s;
        for(int i = 0 ; i < n ; i++)
           s.insert(find(i));
        
        return s.size(); 

    }
};
