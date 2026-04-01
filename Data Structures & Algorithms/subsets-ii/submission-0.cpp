class Solution {
    vector<vector<int>> out;
public:

    void backtracking(int n, vector<int>& current,vector<int>& nums ){
        out.push_back(current);

        for(int i = n; i < nums.size(); i++){
            if (i > n && nums[i] == nums[i - 1]) {
                continue;
            }
            current.push_back(nums[i]);
            backtracking(i+1, current, nums);
            current.pop_back();
        }

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
                sort(nums.begin(), nums.end());

        vector<int> current;
        out.reserve(pow(2,nums.size()));
        backtracking(0, current, nums);
        return out;
    }
};