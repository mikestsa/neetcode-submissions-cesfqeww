class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> s;
        for(auto num : nums){
            if (s.find(num) != s.end()) return true;
            s.insert(num);
        }
        return false;
    }
};