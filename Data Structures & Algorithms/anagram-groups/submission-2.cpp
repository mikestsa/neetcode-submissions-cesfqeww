class Solution {
public:
    std::string get_key_from(const std::string& s){
        vector<int> v(26,0);
        for(auto c : s){
            v[c - 'a']++;
        }
        std::string out;
        for(auto count : v){
            out += to_string(count) + ',';
        }
        return out;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, std::vector<string>> m;
        for(const string& str : strs){
           
            m[get_key_from(str)].push_back(str);
        }
        vector<vector<string>> out;
        for(auto& [key, val] : m){
            out.push_back(val);
        }
        return out;
    }
};
