class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        nums.reserve(nums.size()*2);
        for(int num : nums) nums.push_back(num);
        return nums;
    }
};