class Solution {
public:

    void dfs(int i, vector<int>& current, int& current_sum, int target, vector<vector<int>>& result, vector<int>& nums){
        if (current_sum > target) return;
        if (current_sum == target){
            result.push_back(current);
            return;
        }
        for(int j = i ; j < nums.size(); j++){
            int num = nums[j];
            current.push_back(num);
            current_sum += num;
            dfs(j,current, current_sum, target, result, nums);
            current_sum -= num;
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
       vector<vector<int>>  res;
       vector<int> current; 
       int current_sum = 0;
        dfs(0,current, current_sum, target,res, nums);
        return res;

    }
};
