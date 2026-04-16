class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int out = nums[0];
        int min = 0;
        int max = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            int current = nums[i];

            if (min == 0 || max == 0){
                min = current;
                max = current;
            } 
            else if (current == 0){
                min = 0;
                max = 0;
            }
            else{
                int temp = min;
                min = std::min({current*max, current*min, current});
                max = std::max({current*max, current*temp, current});
            }
            out = std::max(out, max);
        }
        return out;
        
    }
};
