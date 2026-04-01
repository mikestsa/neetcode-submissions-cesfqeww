class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_index;
        for(int i = 0 ; i < nums.size(); i++){
            int remaining_target = target - nums[i];
            if (auto it = num_index.find(remaining_target); it != num_index.end()){
                return {it->second, i};
            }
            num_index[nums[i]] = i;
        }
        return {-1, -1};
    }
};
