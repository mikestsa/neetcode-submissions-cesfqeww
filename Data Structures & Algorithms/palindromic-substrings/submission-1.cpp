class Solution {
public:
    int countSubstrings(string s) {
        int out = s.size();
        for(int size = 2; size <= s.size(); size++){
            for( int r = size - 1; r < s.size(); r++){
                int l = r - size + 1;
                int r_copy = r;
                while(l < r_copy){
                if (s[l] != s[r_copy]) break;
                l++;
                r_copy--;
                if (l >= r_copy) out++;
                }
            }
            
        }

        return out;
    }
};
