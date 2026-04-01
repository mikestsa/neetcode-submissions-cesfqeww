class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int i = 0;
        while(true){
            if (i >= strs[0].size()) break;
            char target;
            target = strs[0][i];
            if(std::all_of(strs.begin(), strs.end(), [&](string str){
                return i < str.size() && str[i] == target;
            })){
                i++;
            }
            else{
                break;
            }
        }
        return strs[0].substr(0, i);
    }
};