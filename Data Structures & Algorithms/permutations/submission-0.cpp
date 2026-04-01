class Solution {
    vector<vector<int>> out;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> current;
        permute(nums, current);
        return out;       
        
    }

     void permute(vector<int>& nums, vector<int> current) {
        if (current.size() == nums.size()){
            out.push_back(current);
            return;
        }        
        for(int num : nums){
            if (find(current.begin(), current.end(), num) == current.end()){
                current.push_back(num);
                permute(nums, current);
                current.pop_back();
            }
        }
          
        
    }
};
