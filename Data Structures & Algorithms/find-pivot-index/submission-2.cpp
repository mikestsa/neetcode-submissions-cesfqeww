class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;
        for(int i = 0 ; i < nums.size() ; i++) total += nums[i];
        int right = total;
        int left = 0;
        for(int i = 0 ; i < nums.size(); i++){
            right -= nums[i];
            if (i > 0) left += nums[i - 1];
            if (right == left) return i;

        }
        return -1;
    }
};