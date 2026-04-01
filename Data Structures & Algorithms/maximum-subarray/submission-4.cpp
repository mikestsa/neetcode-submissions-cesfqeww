class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSub = nums[0], curSum = 0;
        for (int num : nums) {
            curSum += num;
            maxSub = max(maxSub, curSum);

            if (curSum < 0) {
                curSum = 0;
            }
        }
        return maxSub;
    }
};