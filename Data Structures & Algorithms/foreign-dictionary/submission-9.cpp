class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;
        for(const auto& word : words){
            for(char c : word){
                if (indegree.find(c) != indegree.end()) continue;
                indegree[c] = 0;
                adj[c] = {};
            }
        }
        for(int i = 0 ; i < words.size() - 1 ; i++){
            string w1 = words[i];
            string w2 = words[i+1];
            size_t min_len = min(w1.size(), w2.size());
            if (w1.size() > w2.size() && (w1.substr(0, min_len) == w2)) return "";
            for(int index = 0 ; index < min_len ; index++){
                if(w1[index] != w2[index]){
                    if (adj[w1[index]].find(w2[index]) == adj[w1[index]].end()){
                        adj[w1[index]].insert(w2[index]);
                        indegree[w2[index]]++;
                    }
                        break;

                }
            }
        }
        queue<char> q;
        for(auto [c, degree] : indegree){
            if (degree == 0) q.push(c);
        }
        string out;
        while(q.size()){
            char current = q.front();
            q.pop();
            out += current;
            for(char neib : adj[current]){
                indegree[neib]--;
                if (indegree[neib] == 0) q.push(neib);
            }
        }
        if (out.size() == indegree.size()) return out;
        return "";
        
    }
};
