class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int l = 0;
        int max = 0;
        for(int i = 0 ; i < s.size() ; i++){
            char c = s[i];
            m[c]++;
            while(m[c] > 1){
                m[s[l]]--;
                l++;
            }
            max = std::max(max, i - l + 1);
        }
        return max;
        
    }
};
