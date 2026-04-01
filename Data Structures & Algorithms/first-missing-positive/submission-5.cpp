class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0 ; i < nums.size() ; i++){
            if (nums[i] <= 0)
            nums[i] = INT_MAX;
        }
        int minn = nums.size() + 1;
        for(int i = 0 ; i < nums.size() ; i ++){
            if (abs(nums[i]) > 0 && abs(nums[i]) <= nums.size()){
                if (nums[abs(nums[i]) - 1] > 0) nums[abs(nums[i]) - 1] = - nums[abs(nums[i]) - 1];
            }
        }
        for(int i = 0 ; i < nums.size(); i++){
            if (nums[i] > 0) return i + 1;
        }
        return minn;
    }
};