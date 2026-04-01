class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int minTotal = nums[0];
        int minCur = nums[0];

        int maxTotal = nums[0];
        int maxCur = nums[0];

        int totalSum = nums[0];

        for(int i = 1 ; i < nums.size(); i++){
            totalSum += nums[i];
            minCur = min(minCur + nums[i], nums[i]);
            minTotal = min(minCur, minTotal);

            maxCur = max(maxCur + nums[i], nums[i]);
            maxTotal = max(maxCur, maxTotal);
        }
        if (totalSum == minTotal) return maxTotal;
        return max(totalSum - minTotal, maxTotal);
    }
};