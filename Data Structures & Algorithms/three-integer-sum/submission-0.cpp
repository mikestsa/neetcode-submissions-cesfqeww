class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> out;
        std::sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            // Βελτιστοποίηση: Αφού ο πίνακας είναι ταξινομημένος, 
            // αν ο πρώτος αριθμός είναι > 0, το άθροισμα αποκλείεται να είναι 0.
            if (nums[i] > 0) break;
            
            // 1. Παράλειψη διπλότυπων για τον δείκτη i
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int target = -nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            
            while (left < right) {
                int sum = nums[left] + nums[right];
                
                if (sum == target) {
                    out.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    
                    // 2. Παράλειψη διπλότυπων για τον δείκτη left
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    
                    // 3. Παράλειψη διπλότυπων για τον δείκτη right
                    while (left < right && nums[right] == nums[right + 1]) right--;
                }
                else if (sum < target) { // Άλλαξα το <= σε < για καλύτερη αναγνωσιμότητα
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        return out;
    }
};