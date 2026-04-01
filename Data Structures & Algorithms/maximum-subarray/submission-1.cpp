class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur_sum = 0;
        int max_sum = nums[0];
        for(auto num : nums){
            cur_sum += num;
            cur_sum = max(num, cur_sum);
            max_sum = max(max_sum, cur_sum);
        }
        return max_sum;

    }
};
