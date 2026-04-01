class Solution {
public:
int rob(vector<int>& nums) {
    if (nums.size() == 1) return nums.back();
        int prv_0 = nums[0];
        int prv_end = nums.back();
        nums[0] = 0;
        int max1 = robhelper(nums);
        nums[0] = prv_0;
        nums[nums.size() - 1] = 0;
        int max2 = robhelper(nums);
        return max(max1, max2);
        
    }
    int robhelper(vector<int>& nums) {
        vector<int> max_money(nums.size());
        max_money[0] = nums[0];
        max_money[1] = max(nums[0], nums[1]);
        for(int i = 2 ; i < nums.size(); i++){
            max_money[i] = max(max_money[i-2] + nums[i], max_money[i-1]);
        }
        return max_money.back();
        
    }
};
