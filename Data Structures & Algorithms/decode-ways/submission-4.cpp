class Solution {
public:
unordered_map<int, int> m;
    int numDecodings(string s) {
        return numDecodings(s, 0);
    }

    int numDecodings(string& s, int start) {
        if (m.find(start) != m.end()) return m[start];
        if (start >= s.size()) return 1;
        if (start == s.size() - 1 ) {
            if (s[start] != '0') return 1;
            return 0;
        }
        if (s[start] == '0') return 0;

        int two_nums = (s[start] - '0')*10 + (s[start + 1] - '0');
        if (two_nums == 10 || two_nums == 20){
            m[start] =  numDecodings(s, start + 2);
            return m[start];
        }
        else if (two_nums > 10 && two_nums < 27){
            m[start] = numDecodings(s, start + 1) + numDecodings(s, start + 2);
            return m[start];
        }
        return m[start] = numDecodings(s, start + 1) ;
        return m[start];
        
    }
};
