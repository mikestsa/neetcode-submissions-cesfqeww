class Solution {
public:
    string longestPalindrome(string s) {
        string out;
        for(int i = 0 ; i < s.size() ; i++){
            string odd = longestPalindromeOdd(s,i);
            if (odd.size() > out.size()) out = odd;
            string even = longestPalindromeEven(s,i);
            if (even.size() > out.size()) out = even;
        }
        return out;
        
    }

    string longestPalindromeOdd(string s, int i ) {
        int left = i;
        int right = i;
        while(left - 1 >= 0 && right + 1 < s.size() && (s[left - 1] == s[right + 1])){
            left--;
            right++;
        }
        return s.substr(left, right - left + 1);        
    }

    string longestPalindromeEven(string s, int i ) {
        int left = i - 1;
        int right = i;
        if (s[left] != s[right]) return "";
        while(left - 1 >= 0 && right + 1 < s.size() && (s[left - 1] == s[right + 1])){
            left--;
            right++;
        }
        return s.substr(left, right - left + 1);       
        
    }
};
