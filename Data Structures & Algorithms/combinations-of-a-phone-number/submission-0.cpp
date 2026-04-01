class Solution {
    vector<string> out;
     vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl",
                                  "mno", "qprs", "tuv", "wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return out;
        string curr;
        letterCombinations(digits, curr);
        return out;        
    }

    void letterCombinations(string digits, string& curr) {
        if (curr.size() == digits.size()){
            out.push_back(curr);
            return;
        }
        string next_letter = digitToChar[digits[curr.size()] - '0'];
        for(auto c : next_letter){
            curr += c;
            letterCombinations(digits, curr);
            curr.pop_back();
        }

        
        
    }
};
