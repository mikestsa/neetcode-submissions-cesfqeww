class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> m;
        vector<int> out;
        for(char c : s) m[c]++;

        unordered_map<char, int> current;
        int size = 0;
        for(char c : s){
            size++;
            current[c]++;
            if (current[c] == m[c]) current.erase(c);
            if(current.empty()){
                out.push_back(size);
                size = 0;
            }
        }
        return out;
    }
};
