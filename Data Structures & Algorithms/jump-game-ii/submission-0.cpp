class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int next_approachable  = nums[0];
        int current_steps = 1;
        int current_approachable = nums[0];
        for(int i = 0 ; i < nums.size() ; i++){
            if(i > current_approachable){
                current_steps++;
                current_approachable = next_approachable;
            }
            next_approachable = max(next_approachable, nums[i] + i);

        }
        return current_steps;
        
        
    }
};
