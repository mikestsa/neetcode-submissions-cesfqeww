class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        while(i < nums.size()){
            int num = nums[i];
            if (num > 0 && num <= nums.size()){
                if (nums[num - 1] != num){
                    swap(nums[i], nums[num - 1]);
                    i--;
                }                
            }
            i++;

        }
        for(int i = 0 ; i < nums.size() ; i++){
            if (nums[i] != i + 1) return i + 1;
        }
        return nums.size() + 1;
    }
};