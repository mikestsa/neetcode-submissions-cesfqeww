class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int current = nums[0];
        int counter = 1;
        int i = 1;
        while( i < nums.size()){
            if (nums[i] == current){
                counter++;
            }
            else{
                counter--;
            }if (counter < 0){
                counter = 0;
                current = nums[i];
            }
            i++;
        }
        return current;
    }
};