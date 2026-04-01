class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        int size_s1 = s1.size();
        int size_s2 = s2.size();
        unordered_map<char, int> m;
        for(auto c : s1) m[c]++;
        for(int i = 0 ; i < size_s1 ; i++){
            m[s2[i]]--;
            if (m[s2[i]] == 0) m.erase(s2[i]);
        }
        if (m.empty()) return true;
        for(int i = size_s1 ; i < size_s2; i++){
            m[s2[i - size_s1]]++;
            m[s2[i]]--;
            if (m[s2[i]] == 0) m.erase(s2[i]);
            if (m[s2[i - size_s1]] == 0) m.erase(s2[i - size_s1]);
            if (m.empty()) return true;


        }
        return false;
        
    }
};
