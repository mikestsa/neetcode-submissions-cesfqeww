class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total_sum = 0;
        for(auto num : nums) total_sum += num;
        if (total_sum%2) return false;
        int target = total_sum/2;

        unordered_set<int> possible;
        for(auto num : nums){
            if (num == target) return true;

            if (num < target){
                unordered_set<int> curr_possible;

                for(auto poss : possible){
                    if (poss + num == target) return true;
                    else if (poss + num < target) curr_possible.insert(poss + num);
                }
                curr_possible.insert(num);
                for(auto poss : curr_possible) possible.insert(poss);

            }  
        }
        return false;        
    }
};
