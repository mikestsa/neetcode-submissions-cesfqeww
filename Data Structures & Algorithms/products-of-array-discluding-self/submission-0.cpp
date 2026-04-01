class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size());
        left[0] = nums[0];
        for(int i = 1 ; i < nums.size() ; i++){
            left[i] = left[i-1]* nums[i];
        }
        vector<int> right(nums.size());

        right[right.size() - 1] = nums[nums.size() - 1];
        for(int i = right.size() - 2 ; i >= 0; i--){
            right[i] = right[i+1]* nums[i];
        }

        vector<int> out(nums.size());
        out[0] = right[1];
        out[nums.size() - 1] = left[nums.size() - 2];
        for(int i = 1 ; i < nums.size() - 1; i++){
            out[i] = left[i-1] * right[i + 1];
        }
        return out;

    }
};
