class Solution {
    vector<int> memo;
public:
    int longestCommonSubsequence(string& text1, string &text2) {
        memo.resize(text1.size()* text2.size());
        std::fill(memo.begin(), memo.end(), -1);
        return longestCommonSubsequence(text1, text2, 0, 0);
    }
    int longestCommonSubsequence(string& text1, string& text2, int i1, int i2) {
        if(i1 >= text1.size() || i2 >= text2.size()) return 0;
        if (memo[text2.size()*i1 + i2] != -1) return memo[text2.size()*i1 + i2];

        if (text1[i1] == text2[i2]) return 1 + longestCommonSubsequence(text1, text2, i1 + 1, i2 + 1);
        else {
            memo[text2.size()*i1 + i2]  = max(longestCommonSubsequence(text1, text2, i1, i2 + 1),
        longestCommonSubsequence(text1, text2, i1 + 1, i2));
            return memo[text2.size()*i1 + i2];
        }

        
    }
};
