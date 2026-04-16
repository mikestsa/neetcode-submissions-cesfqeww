class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int max = 1;
        for(int i = nums.size() - 1 ; i >= 0 ; i --){
            for(int j = i + 1; j < nums.size() ; j++){

                if(nums[i] < nums[j]){
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
                max = std::max(max, dp[i]);

            }
            
        }
        return max;
    }
};
