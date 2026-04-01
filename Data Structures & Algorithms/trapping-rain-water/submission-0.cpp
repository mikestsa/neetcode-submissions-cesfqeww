class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left_max(height.size());
        int max = INT_MIN;;
        for(int i = 0 ; i < height.size(); i++){
            max = std::max(max, height[i]);
            left_max[i] = max;
        }
     
        
        vector<int> right_max(height.size());
        max = INT_MIN;
        for(int i = height.size() - 1 ; i >= 0; i--){
            max = std::max(max, height[i]);
            right_max[i] = max;
        }

        int total = 0;
        for(int i = 1 ; i < height.size() - 1 ; i++){
            int min_left_right = std::min(left_max[i-1], right_max[i+1]);
            if (min_left_right > height[i]) total += min_left_right - height[i];
        }

        return total;

    }
};
