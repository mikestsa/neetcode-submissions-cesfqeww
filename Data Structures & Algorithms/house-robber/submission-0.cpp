class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> max_money(nums.size());
        max_money[0] = nums[0];
        max_money[1] = max(nums[0], nums[1]);
        for(int i = 2 ; i < nums.size(); i++){
            max_money[i] = max(max_money[i-2] + nums[i], max_money[i-1]);
        }
        return max_money.back();
        
    }
};
