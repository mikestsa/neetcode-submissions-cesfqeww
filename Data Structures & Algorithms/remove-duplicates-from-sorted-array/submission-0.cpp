class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int write = 0;
        for(int r = 1 ; r < nums.size() ; r++){
            if(nums[r] != nums[write]){
                write++;
                nums[write] = nums[r];
            }
        }
        return write + 1;
    }
};