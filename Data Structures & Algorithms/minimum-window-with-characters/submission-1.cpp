class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        int S = s.size();
        int T = t.size();
        int shortest_left = 0;
        int shortest_right = INT_MAX;
        int common_elems = 0;
        unordered_map<char, int> counter;
        for(char c : t) counter[c]++;
        int left = 0;
        for(int right = 0 ; right < S ; right++){
            counter[s[right]]--;
            if (counter[s[right]] >= 0) common_elems++;
            if (common_elems == T){
                while(counter[s[left]] != 0){
                    counter[s[left]]++;

                    left++;
                }
                if (right - left < shortest_right - shortest_left){
                    shortest_right = right;
                    shortest_left = left;
                }
                

            }
        }

    if (shortest_right == INT_MAX) return "";
    return s.substr(shortest_left, shortest_right - shortest_left + 1);
        
    }
};
