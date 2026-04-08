class Solution {
    vector<vector<string>> out;
public:
    vector<vector<string>> partition(string s) {
        out.clear();
        vector<string> partition;
        dfs(0, s, partition);
        return out;
    }
    bool isPalindrome(string& s){
        int left = 0 ;
        int right = s.size() - 1;
        while(left < right){
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    void dfs(int i, string& s, vector<string>& partition){
        if (i >= s.size()){
            out.push_back(partition);
        }
        for(int j = i + 1; j <= s.size(); j++){
            string current = s.substr(i, j - i);
            if (isPalindrome(current)){
                partition.push_back(current);
                dfs(j, s, partition);
                partition.pop_back();
            }
        }

    }
};
