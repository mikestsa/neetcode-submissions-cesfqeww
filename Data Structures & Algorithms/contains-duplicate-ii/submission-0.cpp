class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int left = 0;
        unordered_set<int> s;
        for(int right = 0; right < nums.size(); right++){
            if (right - left > k){
                s.erase(nums[left]);
                left++;
            }
            
            if (s.find(nums[right]) != s.end()) return true;
            s.insert(nums[right]);
        }
        return false;
        
    }
};