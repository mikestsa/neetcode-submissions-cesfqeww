class NumArray {
    vector<int> prefix;

public:

    NumArray(vector<int>& nums) {
        prefix.resize(nums.size());
        int total_sum = 0;
        for(int i = 0 ; i < nums.size(); i++){
            total_sum += nums[i];
            prefix[i] = total_sum;
        }
        
    }
    
    int sumRange(int left, int right) {
        if (left == 0) return prefix[right] ;
        return prefix[right] - prefix[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and calle



















$0d as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */