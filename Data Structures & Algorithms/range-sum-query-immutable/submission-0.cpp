class NumArray {
    int total_sum = 0;
    vector<int> prefix;
    vector<int> sufix;

public:

    NumArray(vector<int>& nums) {
        prefix.resize(nums.size());
        sufix.resize(nums.size());
        for(int i = 0 ; i < nums.size(); i++){
            total_sum += nums[i];
            prefix[i] = total_sum;
        }
        total_sum = 0;
        for(int i = nums.size() - 1 ; i >= 0; i--){
            total_sum += nums[i];
            sufix[i] = total_sum;
        }
        
    }
    
    int sumRange(int left, int right) {
        int pre = 0;
        if (left > 0) pre = prefix[left - 1];
        int s = 0;
        if (right < prefix.size() - 1) s = sufix[right + 1];
        return total_sum -pre - s;
    }
};

/**
 * Your NumArray object will be instantiated and calle



















$0d as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */