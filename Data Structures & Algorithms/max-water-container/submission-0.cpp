class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int max = 0;
        while(left < right){
            int water = (right - left)*std::min(heights[right], heights[left]);
            max = std::max(max, water);
            if (heights[left] < heights[right]) left++;
            else right--;
        }
        return max;
    }
};
