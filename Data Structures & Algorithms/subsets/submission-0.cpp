class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> out;
        if (nums.empty()) return out;
        out.push_back({});
        out.push_back({nums[0]});
        for(int i = 1 ; i < nums.size(); i++){
            vector<vector<int>> copy = out;
            for (auto &v :out) v.push_back(nums[i]);
            out.insert(out.end(), copy.begin(), copy.end());
        }
        return out;

        
    }
};
