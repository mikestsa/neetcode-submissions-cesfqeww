class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> m;
        int left = 0;
        int max = 0;
        int maxf = 0;
        for(int i  = 0; i < s.size() ; i++){
            m[s[i]]++;
            maxf = std::max(maxf, m[s[i]]);

            while(i - left + 1 > maxf + k){
                m[s[left]]--;
                left++;
            }
            max = std::max( i - left + 1, max);
        }

        return max;
        
    }
};
