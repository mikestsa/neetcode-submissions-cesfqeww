class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> counter;
        for(auto c : s) counter[c]++;
        for(auto c : t){
            counter[c]--;
            if (counter[c] == 0 ) counter.erase(c);
        }
        return counter.empty();
    }
};
