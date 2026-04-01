class Solution {
public:
    int numDecodings(string s) {
        return numDecodings(s, 0);
    }

    int numDecodings(string s, int start) {
        if (start >= s.size()) return 1;
        if (start == s.size() - 1 ) {
            if (s[start] != '0') return 1;
            return 0;
        }
        if (s[start] == '0') return 0;

        int two_nums = (s[start] - '0')*10 + (s[start + 1] - '0');
        if (two_nums == 10 || two_nums == 20){
            return  numDecodings(s, start + 2);
        }
        else if (two_nums > 10 && two_nums < 27){
            return numDecodings(s, start + 1) + numDecodings(s, start + 2);
        }
        return numDecodings(s, start + 1) ;
        
    }
};
