class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size());
        for(string word : wordDict){
            int size = word.size();
            if (size > s.size()) continue;

            if (s.find(word) == 0){
                dp[size - 1] = true;
                if (size == s.size()) return true;
            }
        }
        for(int i = 0 ; i < s.size(); i++){
            if (dp[i]){
                string sub(s.begin()+ i+ 1, s.end());
                for(string word : wordDict){
                    int size = word.size();
                    if (size > sub.size()) continue;
                    if (int indx = sub.find(word) == 0){
                        dp[size + i] = true;
                        if (dp.back()) return true;
                    }
                }

            }
        }
        return false;
        
    }
};
