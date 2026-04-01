class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, std::vector<string>> m;
        for(const string str : strs){
            string key = str;
            std::sort(key.begin(), key.end());
            m[key].push_back(str);
        }
         vector<vector<string>> out;
        for(auto [key, val] : m){
            out.push_back(val);
        }
        return out;
    }
};
