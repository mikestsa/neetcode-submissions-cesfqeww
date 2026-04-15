class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        string out;
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;
        for(auto word : words){
            for(char c : word){
                adj[c] = unordered_set<char>();
                indegree[c] = 0;
            }
            
        }
        for(int i = 0 ; i < words.size() - 1 ; i++){
            const string &word1 = words[i];
            const string &word2 = words[i+1];
            int minLen = min(word1.size(), word2.size());
            if (word1.size() > word2.size() &&
                word1.substr(0, minLen) == word2.substr(0, minLen)) {
                return "";
            }
            for (int j = 0; j < minLen; j++) {
                if (word1[j] != word2[j]) {
                    if (!adj[word1[j]].count(word2[j])) {
                        adj[word1[j]].insert(word2[j]);
                        indegree[word2[j]]++;
                    }
                    break;
                }
            }
        }
        

        queue<char> q;
        for (auto &[c, deg] : indegree) {
            if (deg == 0) {
                q.push(c);
            }
        }
        while (!q.empty()) {
            char char_ = q.front();
            q.pop();
            out += char_;
            for (char neighbor : adj[char_]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return out.size() == indegree.size() ? out : "";
        
    }
};
