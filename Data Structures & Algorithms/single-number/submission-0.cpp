class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int out =0;
        for(auto num : nums) out ^= num;
        return out;
        
    }
};
