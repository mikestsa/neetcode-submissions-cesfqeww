class Solution {
    vector<string> out;
public:
    vector<string> generateParenthesis(int n) {
        string s;
        generateParenthesis(n, 0, 0, s);
        return out;
    }

    void generateParenthesis(int n, int left, int right, std::string& s) {
        if(s.size() == 2*n) {
            out.push_back(s);
            return;
        }
        if (left < n){
            s += '(';
            generateParenthesis(n, left + 1, right, s);
            s.pop_back();
        }
        if (right < left){
            s += ')';
            generateParenthesis(n, left, right + 1, s);
            s.pop_back();
        }


    }
};
