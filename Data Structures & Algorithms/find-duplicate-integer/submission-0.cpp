class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        

        for(int i = 0 ; i < nums.size() ; i++){
            int num = nums[i];
            if (nums[abs(num)] < 0) return abs(num);
            nums[abs(num)] *= -1;
        }
         for(int i = 0 ; i < nums.size() ; i++){
            nums[i] = abs(nums[i]);
        }
        return 0;
        

    }
};
