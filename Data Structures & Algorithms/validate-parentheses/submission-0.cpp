class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) return true;
        unordered_map<char, char> m;
        m['('] = ')';
        m['{'] = '}';
        m['['] = ']';
        stack<char> st;
        st.push(s[0]);
        for(int i = 1; i < s.size() ; i++){
            char c = s[i];
            if (st.size() && m[st.top()] == c) st.pop();
            else {st.push(s[i]);}
        }
        return st.empty();
    }
};
