class Solution {
    vector<vector<int>> out;
    vector<int> current_v;

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        combinationSum2(candidates, 0, target, 0);
        return out;        
    }

    void combinationSum2(vector<int>& candidates, int index, int target, int current) {
        if (index > candidates.size()) return;
        if(current == target){
            out.push_back(current_v);
            return;

        } 
        
        if (current > target) return;
        current_v.push_back(candidates[index]);
        current += candidates[index];
        combinationSum2(candidates, index +1, target, current);
        current_v.pop_back();
        current -= candidates[index];
        while(candidates[index + 1] == candidates[index]) index++;
        combinationSum2(candidates, index +1, target, current);



    }
};
