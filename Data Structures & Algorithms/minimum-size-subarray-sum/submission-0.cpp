class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left =0;
        int sum = 0;
        int min = INT_MAX;
        for(int i = 0 ; i < nums.size(); i++){
            sum += nums[i];
            while (sum >= target){
                min = std::min(min, i - left + 1);
                sum -= nums[left];
                left++;
            } 
        }
        if (min == INT_MAX) return 0;
        return min;
        
    }
};